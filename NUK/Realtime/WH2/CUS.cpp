#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <limits>

#ifdef ENABLE_TIMING
    // 若編譯時加上 -DENABLE_TIMING，會啟用整體執行時間量測
    #include <chrono>
    using namespace std::chrono;

    // 這些是全域變數（但 main 裡又宣告了同名 start，會遮蔽它）
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto durat = duration_cast<nanoseconds>(stop - start);
#endif

using namespace std;

// =========================
// 模擬參數
// =========================
static const int SIM_TIME = 1000;      // 模擬總時間長度：0..999 共 1000 個時間單位
static const double SERVER_U = 0.2;    // 作業指定 server size / bandwidth = 0.2（20%）

// =========================
// 資料結構：週期性任務/工作
// =========================

// 週期性任務（Task）定義：每個 task 會不斷釋放 job
struct PeriodicTask {
    int id;       // 任務編號（由讀檔順序自動給：0,1,2,...）
    int period;   // 週期 T
    int exec;     // 每次釋放所需執行時間 C
};

// 週期性工作（Job）：某個 task 在某次 release 產生的一次工作
struct PeriodicJob {
    int task_id;   // 來源任務 id
    int release;   // 釋放時間
    int deadline;  // 絕對截限時間（absolute deadline）= release + period
    int remaining; // 剩餘執行時間（每跑 1 time unit 就 -1）
};

// =========================
// 資料結構：非週期性工作
// =========================
struct AperiodicJob {
    int id;            // 工作編號（由讀檔順序自動給）
    int arrival;       // 抵達時間 r
    int exec;          // 執行時間 e
    int remaining;     // 剩餘執行時間

    // 這份作業的「投影片版本」CUS/TBS 是用 server 的 deadline d / budget es 來控制，
    // 不需要在每個 job 上存 deadline；但保留這欄位也不影響（這裡不使用）。
    long long deadline; // 保留欄位（這份投影片版程式沒用到）

    int start_time;    // 第一次開始執行的時間（-1 表示從未開始）
    int finish_time;   // 完成時間（-1 表示在 SIM_TIME 內沒完成）
};

// =======================================================
// 工具函式：解析一行 "a,b"（允許空白）
// =======================================================
static bool parse_two_ints_csv_line(const string& line, int &a, int &b) {
    // 允許空白：例如 "1,3 " 或 "  1, 3"
    string s = line;

    // 1) trim 去除頭尾空白
    auto l = s.find_first_not_of(" \t\r\n");
    if (l == string::npos) return false;
    auto r = s.find_last_not_of(" \t\r\n");
    s = s.substr(l, r - l + 1);

    // 2) 找逗號分隔
    size_t comma = s.find(',');
    if (comma == string::npos) return false;

    // 3) 分左右字串
    string left = s.substr(0, comma);
    string right = s.substr(comma + 1);

    // 4) 各自 trim
    auto trim = [](string x){
        auto l2 = x.find_first_not_of(" \t\r\n");
        if (l2 == string::npos) return string();
        auto r2 = x.find_last_not_of(" \t\r\n");
        return x.substr(l2, r2 - l2 + 1);
    };
    left = trim(left);
    right = trim(right);
    if (left.empty() || right.empty()) return false;

    // 5) stoi 轉整數
    try {
        a = stoi(left);
        b = stoi(right);
    } catch (...) {
        return false;
    }
    return true;
}

// =======================================================
// 讀 periodic.txt：每行 "period, exec"
// =======================================================
static vector<PeriodicTask> load_periodic(const string& path) {
    ifstream fin(path);
    if (!fin.is_open()) {
        cerr << "Cannot open periodic file: " << path << "\n";
        return {};
    }

    vector<PeriodicTask> tasks;
    string line;
    int id = 0;

    // 逐行讀
    while (getline(fin, line)) {
        int p, e;
        if (!parse_two_ints_csv_line(line, p, e)) continue;
        // 作業說 period/exec 為正整數
        if (p <= 0 || e <= 0) continue;
        tasks.push_back({id++, p, e});
    }
    return tasks;
}

// =======================================================
// 讀 aperiodic.txt：每行 "arrival, exec"
// =======================================================
static vector<AperiodicJob> load_aperiodic(const string& path) {
    ifstream fin(path);
    if (!fin.is_open()) {
        cerr << "Cannot open aperiodic file: " << path << "\n";
        return {};
    }

    vector<AperiodicJob> jobs;
    string line;
    int id = 0;

    while (getline(fin, line)) {
        int r, e;
        if (!parse_two_ints_csv_line(line, r, e)) continue;

        // arrival 可為 0（作業範例也可能會出現 0）
        // exec 必須正整數
        if (r < 0 || e <= 0) continue;

        AperiodicJob j;
        j.id = id++;
        j.arrival = r;
        j.exec = e;
        j.remaining = e;

        // 這裡先初始化其他欄位
        j.deadline = -1;
        j.start_time = -1;
        j.finish_time = -1;
        jobs.push_back(j);
    }

    // 依 arrival 時間排序；若 arrival 相同，保留原始檔案順序（stable_sort）
    stable_sort(jobs.begin(), jobs.end(),
        [](const AperiodicJob& a, const AperiodicJob& b){
            return a.arrival < b.arrival;
        }
    );

    return jobs;
}

// =======================================================
// EDF 挑選「週期性工作」：
// - 先比絕對 deadline 小者優先
// - deadline 相同時：task_id 小者優先（作業 PS(2)）
// 注意：server vs periodic 若 deadline 相同 => server 先，這裡不處理，外層處理。
// =======================================================
static int pick_periodic_job_index_edf(const vector<PeriodicJob>& active) {
    int best = -1;
    for (int i = 0; i < (int)active.size(); ++i) {
        if (active[i].remaining <= 0) continue;

        if (best == -1) { best = i; continue; }

        if (active[i].deadline < active[best].deadline) best = i;
        else if (active[i].deadline == active[best].deadline) {
            // deadline 相同 => 任務 ID 小者優先
            if (active[i].task_id < active[best].task_id) best = i;
        }
    }
    return best;
}

// =======================================================
// 統計資料（作業輸出用）
// =======================================================
struct Metrics {
    long long periodic_total = 0;      // 週期性工作總數（每釋放一次 job 就 +1）
    long long periodic_miss = 0;       // 週期性 miss 數（deadline 到了還沒做完就算 miss 丟棄）
    long long aperiodic_done = 0;      // 完成的非週期性工作數
    long long aperiodic_sum_resp = 0;  // Σ(完成時間 - 抵達時間)
};

// =======================================================
// helper：計算 e/U
// 因為 U = 0.2 => e/U = 5e，對整數 e 完全沒有誤差
// =======================================================
static inline long long server_cost_over_u(int e) {
    return 5LL * (long long)e;
}

// =======================================================
// CUS (Constant Utilization Server) - 完全照投影片規則 R1/R2/R3
//
// 投影片重點：
// - server 有兩個狀態：deadline d、budget es
// - CUS 的 replenishment（補 budget）只會在「server deadline d 時刻」發生（R3）
// - 當 job 抵達且 queue 原本是空時：
//      * 若 t < d：R2a do nothing（表示要等到 d 才能補 budget）
//      * 若 t >= d：R2b 設定 d = t + e/U、es = e
//
// EDF 排程規則（作業要求）：
// - server 與 periodic deadline 相同 => server 先跑（PS(1)）
// - periodic deadline 相同 => task_id 小者先跑（PS(2)）
// =======================================================
static void simulate_CUS(
    const vector<PeriodicTask>& tasks,
    const vector<AperiodicJob>& aperiodic_in,
    const string& out_path
) {
    ofstream out(out_path);
    if (!out.is_open()) {
        cerr << "Cannot open output: " << out_path << "\n";
        return;
    }

    // activeP：目前存在的週期性 jobs（尚未完成且未被丟棄）
    vector<PeriodicJob> activeP;
    activeP.reserve(tasks.size());

    // arriving：尚未到達的 aperiodic jobs（依 arrival 排序）
    deque<AperiodicJob> arriving(aperiodic_in.begin(), aperiodic_in.end());

    // ap_queue：已到達等待服務的 aperiodic jobs（FCFS，永遠服務 front）
    deque<AperiodicJob> ap_queue;

    Metrics M;

    // ---- CUS server state（R1 初始化）----
    int es = 0;        // server budget（可服務 aperiodic 的剩餘時間）
    long long d = 0;   // server deadline（絕對時間）

    // =========================
    // 主模擬迴圈：每個時間單位 t
    // =========================
    for (int t = 0; t < SIM_TIME; ++t) {

        // (1) 釋放週期性 jobs
        // 每個 task 在 t%period==0 釋放一個 job
        for (auto &tk : tasks) {
            if (t % tk.period == 0) {
                // deadline = t + period（絕對截限時間）
                // remaining = exec
                PeriodicJob pj{tk.id, t, t + tk.period, tk.exec};
                activeP.push_back(pj);
                M.periodic_total++;
            }
        }

        // (2) 將已到達的 aperiodic jobs 移入 ap_queue
        // 並在「抵達時 queue 原本是空」的情況下，套用 CUS 的 R2 規則
        while (!arriving.empty() && arriving.front().arrival <= t) {
            bool was_empty = ap_queue.empty();

            ap_queue.push_back(arriving.front());
            arriving.pop_front();

            // 只有「到達前是空 queue」才觸發 R2（投影片寫法）
            if (was_empty) {
                int e = ap_queue.front().exec; // 新 job 的執行時間 e（front）

                if ((long long)t < d) {
                    // R2a: t < d => do nothing
                    // 意味著：雖然 queue 變成非空，但 CUS 不會立刻補 budget
                    // 會等到 t == d 時，由 R3a 才補 budget
                } else {
                    // R2b: t >= d => d = t + e/U, es = e
                    d = (long long)t + server_cost_over_u(e);
                    es = e;
                }
            }
        }

        // (3) 週期性 deadline miss 檢查
        // 作業採用：若 job.deadline == t，代表必須在 t-1 結束前完成
        // 因此在 t 的開頭檢查，若 remaining>0 則 miss 丟棄
        for (auto &pj : activeP) {
            if (pj.remaining + t > pj.deadline) {
                M.periodic_miss++;
                pj.remaining = 0; // drop（直接丟棄沒完成的部分）
            }
        }

        // 移除已完成或被丟棄的週期性 job
        activeP.erase(remove_if(activeP.begin(), activeP.end(),
            [](const PeriodicJob& pj){ return pj.remaining <= 0; }),
            activeP.end()
        );

        // (4) CUS R3：在 server deadline d 的時刻，才補 budget
        // 離散時間中：我們在時間 t 開頭若 t==d，視為到達 deadline
        if ((long long)t == d) {
            if (!ap_queue.empty()) {
                // R3a: backlogged（queue 非空）
                // => d = d + e/U, es = e
                int e = ap_queue.front().exec;
                d = d + server_cost_over_u(e);
                es = e;
            } else {
                // R3b: idle（queue 空）=> do nothing
            }
        }

        // (5) EDF 排程決策：在「server」與「週期性 job」之間選擇
        bool server_runnable = (!ap_queue.empty() && es > 0); // 有工作且有 budget 才能跑 server
        int bestP = pick_periodic_job_index_edf(activeP);     // 週期性 EDF 最優者

        bool run_server = false;

        if (!server_runnable && bestP == -1) {
            // 兩邊都不能跑 => CPU idle
        } else if (server_runnable && bestP == -1) {
            // 只有 server 可以跑
            run_server = true;
        } else if (!server_runnable && bestP != -1) {
            // 只有 periodic 可以跑
            run_server = false;
        } else {
            // 兩邊都可跑 => 比較 deadline
            long long pd = activeP[bestP].deadline; // periodic 絕對截限
            long long sd = d;                       // server 絕對截限（投影片用 d）

            if (sd < pd) run_server = true;
            else if (sd > pd) run_server = false;
            else {
                // PS(1)：deadline 相同 => server 先
                run_server = true;
            }
        }

        // (6) 執行 1 個時間單位
        if (run_server) {
            // 執行 server：服務 aperiodic queue 的第一個工作（FCFS）
            AperiodicJob &job = ap_queue.front();

            // 記錄第一次開始執行時間
            if (job.start_time == -1) job.start_time = t;

            job.remaining--;
            es--; // server budget 減 1

            // 如果此 aperiodic job 完成
            if (job.remaining == 0) {
                job.finish_time = t + 1; // 在此 time unit 結束時完成
                M.aperiodic_done++;
                M.aperiodic_sum_resp += (job.finish_time - job.arrival);

                ap_queue.pop_front();

                // 注意：CUS 不會在 job 完成時補下一個 budget
                // 下一次補 budget 只會在 t==d 的 R3 事件發生
            }
        } else if (bestP != -1) {
            // 執行週期性 job（EDF 選到的那個）
            activeP[bestP].remaining--;
        } else {
            // CPU idle
        }
    }

    // =========================
    // 輸出結果
    // =========================
    out << "=== CUS Simulation (Slide R1/R2/R3) ===\n";
    out << "SIM_TIME = " << SIM_TIME << "\n";
    out << "Server Utilization = " << SERVER_U << "\n\n";

    // miss rate = miss / total
    double miss_rate = (M.periodic_total == 0)
        ? 0.0
        : (double)M.periodic_miss / (double)M.periodic_total;

    out << "Periodic total jobs = " << M.periodic_total << "\n";
    out << "Periodic missed jobs = " << M.periodic_miss << "\n";
    out << "Periodic miss rate = " << fixed << setprecision(6) << miss_rate << "\n\n";

    out << "Aperiodic completed jobs = " << M.aperiodic_done << "\n";
    if (M.aperiodic_done == 0) {
        out << "Aperiodic avg response time = N/A (no completed jobs)\n";
    } else {
        double avg_resp = (double)M.aperiodic_sum_resp / (double)M.aperiodic_done;
        out << "Aperiodic avg response time = " << fixed << setprecision(6) << avg_resp << "\n";
    }

    out.close();
}

// =======================================================
// TBS (Total Bandwidth Server) - 完全照投影片規則 R1/R2/R3
//
// 投影片重點：
// - server 同樣有 deadline d、budget es
// - TBS 的 replenishment（補下一個 job 的 budget）發生在「目前 job 完成時」（R3）
// - 當 job 抵達且 queue 原本是空時：
//      d = max(d, t) + e/U, es = e（R2）
//
// EDF tie-break 同作業：
// - deadline 相同 => server 先（PS(1)）
// - periodic deadline 相同 => task_id 小先（PS(2)）
// =======================================================
static void simulate_TBS(
    const vector<PeriodicTask>& tasks,
    const vector<AperiodicJob>& aperiodic_in,
    const string& out_path
) {
    ofstream out(out_path);
    if (!out.is_open()) {
        cerr << "Cannot open output: " << out_path << "\n";
        return;
    }

    vector<PeriodicJob> activeP;
    activeP.reserve(tasks.size());

    deque<AperiodicJob> arriving(aperiodic_in.begin(), aperiodic_in.end());
    deque<AperiodicJob> ap_queue;

    Metrics M;

    // ---- TBS server state（R1 初始化）----
    int es = 0;
    long long d = 0;

    for (int t = 0; t < SIM_TIME; ++t) {

        // (1) 釋放週期性 jobs
        for (auto &tk : tasks) {
            if (t % tk.period == 0) {
                PeriodicJob pj{tk.id, t, t + tk.period, tk.exec};
                activeP.push_back(pj);
                M.periodic_total++;
            }
        }

        // (2) 將到達的 aperiodic jobs 推入 queue
        // 若到達前 queue 為空 => 觸發 TBS 的 R2
        while (!arriving.empty() && arriving.front().arrival <= t) {
            bool was_empty = ap_queue.empty();

            ap_queue.push_back(arriving.front());
            arriving.pop_front();

            if (was_empty) {
                // R2: d = max(d, t) + e/U, es = e
                int e = ap_queue.front().exec;
                d = max(d, (long long)t) + server_cost_over_u(e);
                es = e;
            }
        }

        // (3) periodic deadline miss 檢查
        for (auto &pj : activeP) {
            if (pj.remaining + t > pj.deadline) {
                M.periodic_miss++;
                pj.remaining = 0; // drop
            }
        }
        activeP.erase(remove_if(activeP.begin(), activeP.end(),
            [](const PeriodicJob& pj){ return pj.remaining <= 0; }),
            activeP.end()
        );

        // (4) EDF 排程：server vs periodic
        bool server_runnable = (!ap_queue.empty() && es > 0);
        int bestP = pick_periodic_job_index_edf(activeP);

        bool run_server = false;

        if (!server_runnable && bestP == -1) {
            // idle
        } else if (server_runnable && bestP == -1) {
            run_server = true;
        } else if (!server_runnable && bestP != -1) {
            run_server = false;
        } else {
            long long pd = activeP[bestP].deadline;
            long long sd = d;

            if (sd < pd) run_server = true;
            else if (sd > pd) run_server = false;
            else {
                // PS(1)：deadline 相同 => server 先
                run_server = true;
            }
        }

        // (5) 執行 1 time unit
        if (run_server) {
            AperiodicJob &job = ap_queue.front();

            if (job.start_time == -1) job.start_time = t;

            job.remaining--;
            es--;

            // 若目前 aperiodic job 完成 => 觸發 TBS 的 R3
            if (job.remaining == 0) {
                job.finish_time = t + 1;
                M.aperiodic_done++;
                M.aperiodic_sum_resp += (job.finish_time - job.arrival);

                ap_queue.pop_front();

                // R3: server 完成目前 job 後
                if (!ap_queue.empty()) {
                    // 若 backlogged => 立刻為下一個 job 補 budget，並延後 deadline
                    int e = ap_queue.front().exec;
                    d = d + server_cost_over_u(e);
                    es = e;
                } else {
                    // 若 idle => do nothing
                }
            }
        } else if (bestP != -1) {
            activeP[bestP].remaining--;
        } else {
            // idle
        }
    }

    // 輸出結果
    out << "=== TBS Simulation (Slide R1/R2/R3) ===\n";
    out << "SIM_TIME = " << SIM_TIME << "\n";
    out << "Server Utilization = " << SERVER_U << "\n\n";

    double miss_rate = (M.periodic_total == 0)
        ? 0.0
        : (double)M.periodic_miss / (double)M.periodic_total;

    out << "Periodic total jobs = " << M.periodic_total << "\n";
    out << "Periodic missed jobs = " << M.periodic_miss << "\n";
    out << "Periodic miss rate = " << fixed << setprecision(6) << miss_rate << "\n\n";

    out << "Aperiodic completed jobs = " << M.aperiodic_done << "\n";
    if (M.aperiodic_done == 0) {
        out << "Aperiodic avg response time = N/A (no completed jobs)\n";
    } else {
        double avg_resp = (double)M.aperiodic_sum_resp / (double)M.aperiodic_done;
        out << "Aperiodic avg response time = " << fixed << setprecision(6) << avg_resp << "\n";
    }

    out.close();
}

// =======================================================
// main：讀檔、跑兩種演算法、輸出結果
// =======================================================
int main() {
    // IO 加速
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);

    #ifdef ENABLE_TIMING
        auto start = chrono::high_resolution_clock::now();
    #endif

    // ===== 只要改這裡路徑 =====
    // static const string PERIODIC_PATH  = "data\\simple\\periodic.txt";
    // static const string APERIODIC_PATH = "data\\simple\\aperiodic.txt";
    static const string PERIODIC_PATH  = "data\\complex\\0.8.txt";
    static const string APERIODIC_PATH = "data\\complex\\aperiodic.txt";

    // 讀檔
    auto periodic_tasks = load_periodic(PERIODIC_PATH);
    auto aperiodic_jobs = load_aperiodic(APERIODIC_PATH);

    if (periodic_tasks.empty()) {
        cerr << "No periodic tasks loaded. Check file: " << PERIODIC_PATH << "\n";
    }
    // aperiodic 可以是空的（仍可跑，只是平均反應時間會是 N/A）

    // 跑 CUS 與 TBS（投影片版本）
    simulate_CUS(periodic_tasks, aperiodic_jobs, "result\\complex\\result_CUS_0.8.txt");
    simulate_TBS(periodic_tasks, aperiodic_jobs, "result\\complex\\result_TBS_0.8.txt");

    cout << "Done.\n";
    cout << "Wrote: result\\complex\\result_CUS_0.8.txt\n";
    cout << "Wrote: result\\complex\\result_TBS_0.8.txt\n";

    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
        durat = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << double(durat.count())/1000000.0 << " ms.\n";
    #endif

    return 0;
}

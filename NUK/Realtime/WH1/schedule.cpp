#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <climits>
#include <filesystem>
#include <algorithm>
#include <iomanip>   // for fixed, setprecision
#include <cctype>    // for isdigit
#include "../../penguinLibrary/linklist/linklist.hpp"
#define endl "\n"
using namespace std;
#include <cmath>

class Task{
public:
    int tid;
    int phase;
    int period;
    int relative_deadline;
    int execution_time;
    friend ostream& operator<<(ostream& os, const Task& t){
        os << "T" << t.tid << ": (phase=" << t.phase << ", period=" << t.period
           << ", deadline=" << t.relative_deadline << ", exec_time=" << t.execution_time << ")";
        return os;
    }
};

long long lcm_ll(long long a, long long b) {
    long long x=a, y=b;
    while (y != 0) { long long t = y; y = x % y; x = t; }
    return (a / x) * b;
}

struct Job{
    int tid;
    int remaining;
    int abs_deadline;
    int release_time;
    int period;
    int exec_time;
};

inline ostream& operator<<(ostream& os, const Job& j){
    os << "T" << j.tid << "(r=" << j.release_time << ", d=" << j.abs_deadline << ", rem=" << j.remaining << ")";
    return os;
}

// 取得第 idx 個元素（複製一份）
static Job get_by_index(linklist<Job>& lst, int idx){
    int k=0;
    for(auto it=lst.begin(); it!=lst.end(); ++it, ++k){
        if(k==idx) return *it;
    }
    return Job{};
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);

    int test_num = 6; // test1.txt..test6.txt
    for(int i=1; i<=test_num; ++i){
        string testfile = string("test/test") + to_string(i) + ".txt";
        ifstream file(testfile);
        if(!file.is_open()){
            cerr << "Could not open " << testfile << endl;
            continue;
        }

        vector<Task> tasks;
        string line;
        int local_tid=1;
        while(getline(file, line)){
            bool has_digit=false;
            for(char c: line) if(isdigit((unsigned char)c) || c=='-'){ has_digit=true; break; }
            if(!has_digit) continue;

            for(char &c: line) if(!(isdigit((unsigned char)c) || c=='-')) c=' ';

            istringstream iss(line);
            Task t{};
            if(!(iss >> t.phase >> t.period >> t.relative_deadline >> t.execution_time)){
                iss.clear(); iss.str(line);
                if(iss >> t.phase >> t.period >> t.execution_time){
                    t.relative_deadline = t.period;
                }else continue;
            }
            t.tid = local_tid++;
            tasks.push_back(t);
        }
        if(tasks.empty()){
            cerr << "No tasks parsed from " << testfile << endl;
            continue;
        }

        long long MaxPH = 1;
        for(auto& t: tasks) MaxPH = lcm_ll(MaxPH, t.period);
        if(MaxPH <= 0) MaxPH = 1;

        // utilization & bounds
        int n_tasks = (int)tasks.size();
        double util = 0.0;
        for(auto &t: tasks){
            int denom = std::min(t.period, (t.relative_deadline>0? t.relative_deadline : t.period));
            if(denom <= 0) denom = (t.period>0? t.period:1);
            util += (double)t.execution_time / (double)denom;
        }
        double rm_bound = n_tasks * (pow(2.0, 1.0 / (double)max(1, n_tasks)) - 1.0);
        bool edf_sched = (util <= 1.0 + 1e-12);
        bool rm_sched  = (util <= rm_bound + 1e-12);

        try{ namespace fs=std::filesystem; fs::create_directories("result"); }catch(...){}

        auto simulate = [&](const string& name, auto pick_index)->void{
            string resultfile = string("result/result") + to_string(i) + "_" + name + ".txt";
            ofstream result(resultfile);
            if(!result.is_open()){
                cerr << "Could not open " << resultfile << " for writing." << endl;
                return;
            }
            result << name << " Scheduling Result for " << testfile << ":\n";
            result << "Schedulability tests:\n";
            result << "  Utilization U = " << fixed << setprecision(6) << util << "\n";
            if(name=="edf"){
                result << "  EDF test: sum(e_i/min(p_i,D_i)) <= 1 -> "
                       << (edf_sched?"PASS":"FAIL") << "\n";
            }
            if(name=="rm"){
                result << "  RM test: U <= n(2^{1/n}-1) (bound=" << fixed << setprecision(6) << rm_bound
                       << ") -> " << (rm_sched?"PASS":"FAIL") << "\n";
            }
            result << "\n";

            linklist<Job> ready;
            vector<string> timeline((size_t)MaxPH, "idle");
            int cpu_busy = 0;

            map<int,int> misses;
            map<int,int> completions;
            vector<string> miss_log;

            for(long long t=0; t<MaxPH; ++t){
                // release
                for(auto &task: tasks){
                    if(t >= task.phase && ((t - task.phase) % task.period == 0)){
                        Job j;
                        j.tid = task.tid;
                        j.remaining = task.execution_time;
                        j.exec_time = task.execution_time;
                        j.release_time = (int)t;
                        j.period = task.period;
                        j.abs_deadline = (int)(t + (task.relative_deadline>0?task.relative_deadline:task.period));
                        ready.push_back(j);
                    }
                }

                if(ready.empty()){
                    timeline[(size_t)t] = "idle";
                    continue;
                }

                // pick by policy -> MUST return index in ready
                int pick = pick_index(ready, (int)t);
                if(pick < 0) pick = 0;

                Job cur = get_by_index(ready, pick);
                // run 1 unit
                cur.remaining -= 1;
                cpu_busy++;
                timeline[(size_t)t] = string("T") + to_string(cur.tid);

                // remove chosen node first (avoid in-place mutation on unknown iterator design)
                ready.erase(pick);

                if(cur.remaining <= 0){
                    // finished at t+1
                    if((int)(t+1) > cur.abs_deadline){
                        misses[cur.tid]++;
                        ostringstream ss; ss << "time " << (t+1) << ": T" << cur.tid
                                             << " (r=" << cur.release_time << ", d=" << cur.abs_deadline << ") missed";
                        miss_log.push_back(ss.str());
                    }else{
                        completions[cur.tid]++;
                    }
                }else{
                    // not finished -> requeue
                    ready.push_back(cur);
                }

                // check waiting jobs that already cannot meet their deadlines
                // (collect indexes first to avoid iterator invalidation)
                vector<int> to_remove;
                {
                    int idx=0;
                    for(auto it=ready.begin(); it!=ready.end(); ++it, ++idx){
                        const Job &j = *it;
                        if((int)(t+1) + j.remaining > j.abs_deadline){
                            misses[j.tid]++;
                            ostringstream ss; ss << "time " << (t+1) << ": T" << j.tid
                                                 << " (r=" << j.release_time << ", d=" << j.abs_deadline << ") missed (waiting)";
                            miss_log.push_back(ss.str());
                            to_remove.push_back(idx);
                        }
                    }
                    // remove from back to front
                    sort(to_remove.begin(), to_remove.end());
                    for(int k=(int)to_remove.size()-1; k>=0; --k){
                        ready.erase(to_remove[k]);
                    }
                }
            }

            for(long long t=0; t<MaxPH; ++t){
                result << t << ": " << timeline[(size_t)t] << "\n";
            }
            result << "\nSummary:\n";
            result << "CPU busy time: " << cpu_busy << " / " << MaxPH << "\n";
            int total_misses=0, total_comp=0;
            for(auto &p: completions) total_comp += p.second;
            for(auto &p: misses) total_misses += p.second;
            result << "Completions: " << total_comp << "\n";
            result << "Misses: " << total_misses << "\n";
            result << "\nMiss details:\n";
            if(miss_log.empty()) result << "  (no misses)\n";
            else for(auto &s: miss_log) result << "  " << s << "\n";
            result.close();
        };

        // ===== pickers: 回傳「索引」而非 tid =====
        auto pick_idx_edf = [&](linklist<Job>& ready, int now)->int{
            int best_idx = -1, idx = 0;
            int best_dead = INT_MAX, best_tid = INT_MAX;
            for(auto it=ready.begin(); it!=ready.end(); ++it, ++idx){
                const Job &j = *it;
                if(j.abs_deadline < best_dead || (j.abs_deadline == best_dead && j.tid < best_tid)){
                    best_dead = j.abs_deadline; best_tid = j.tid; best_idx = idx;
                }
            }
            return best_idx<0?0:best_idx;
        };
        auto pick_idx_rm = [&](linklist<Job>& ready, int now)->int{
            int best_idx = -1, idx = 0;
            int best_period = INT_MAX, best_tid = INT_MAX;
            for(auto it=ready.begin(); it!=ready.end(); ++it, ++idx){
                const Job &j = *it;
                if(j.period < best_period || (j.period == best_period && j.tid < best_tid)){
                    best_period = j.period; best_tid = j.tid; best_idx = idx;
                }
            }
            return best_idx<0?0:best_idx;
        };
        auto pick_idx_lst = [&](linklist<Job>& ready, int now)->int{
            int best_idx = -1, idx = 0;
            int best_slack = INT_MAX, best_tid = INT_MAX;
            for(auto it=ready.begin(); it!=ready.end(); ++it, ++idx){
                const Job &j = *it;
                int slack = (j.abs_deadline - now) - j.remaining;
                if(slack < best_slack || (slack == best_slack && j.tid < best_tid)){
                    best_slack = slack; best_tid = j.tid; best_idx = idx;
                }
            }
            return best_idx<0?0:best_idx;
        };

        simulate("edf", [&](linklist<Job>& r, int now){ return pick_idx_edf(r, now); });
        simulate("rm",  [&](linklist<Job>& r, int now){ return pick_idx_rm(r, now); });
        simulate("lst", [&](linklist<Job>& r, int now){ return pick_idx_lst(r, now); });
    }
    return 0;
}

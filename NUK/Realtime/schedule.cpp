#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <climits>
#include <filesystem>
#include <algorithm>
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
    // provide ostream so linklist's operator<< can print Task
    friend ostream& operator<<(ostream& os, const Task& t){
        os << "T" << t.tid << ": (phase=" << t.phase << ", period=" << t.period 
           << ", deadline=" << t.relative_deadline << ", exec_time=" << t.execution_time << ")";
        return os;
    }
};

long long lcm(long long a, long long b) {
    long long temp_a = a, temp_b = b;
    while (temp_b != 0) {
        long long temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    return (a / temp_a) * b;
}

// Job used for runtime ready-queue entries
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int test_num = 6; // reading test1.txt..test6.txt per your request
    for(int i=1;i<=test_num;++i){
        // build filename like "test/test1.txt"
        string testfile = string("test/test") + to_string(i) + ".txt";
        ifstream file(testfile);

        if(!file.is_open()){
            cerr << "Could not open " << testfile << endl;
            continue; // try next file
        }

        // parse tasks from file. Expected each line to contain: phase period relative_deadline execution_time
        // allow separators like '.' or spaces by normalizing non-digit to spaces
        vector<Task> tasks;
        string line;
        int local_tid = 1;
        while(getline(file, line)){
            // skip empty lines
            bool has_digit = false;
            for(char c: line) if(isdigit((unsigned char)c) || c=='-') { has_digit = true; break; }
            if(!has_digit) continue;

            for(char &c: line){
                if(!(isdigit((unsigned char)c) || c=='-' )) c = ' ';
            }
            istringstream iss(line);
            Task t{};
            if(!(iss >> t.phase >> t.period >> t.relative_deadline >> t.execution_time)){
                // try shorter form: phase period execution_time (no explicit deadline)
                iss.clear(); iss.str(line);
                if(iss >> t.phase >> t.period >> t.execution_time){
                    t.relative_deadline = t.period; // assume deadline == period
                } else {
                    continue; // skip malformed line
                }
            }
            t.tid = local_tid++;
            tasks.push_back(t);
        }

        if(tasks.empty()){
            cerr << "No tasks parsed from " << testfile << endl;
            continue;
        }

        int MaxPH = 1;
        for(auto& t : tasks){
            MaxPH = (int)lcm(MaxPH, t.period);
        }

        // compute utilization for schedulability tests
        int n_tasks = (int)tasks.size();
        double util = 0.0;
        for(auto &t: tasks){
            int denom = std::min(t.period, (t.relative_deadline>0? t.relative_deadline : t.period));
            if(denom <= 0) denom = t.period>0? t.period:1;
            util += (double)t.execution_time / (double)denom;
        }
        double rm_bound = n_tasks * (pow(2.0, 1.0 / (double)max(1, n_tasks)) - 1.0);
        bool edf_sched = (util <= 1.0 + 1e-12);
        bool rm_sched = (util <= rm_bound + 1e-12);

        // prepare results directory
        try{
            namespace fs = std::filesystem;
            fs::create_directories("result");
        }catch(...){/* ignore if not available */}

        // use top-level Job struct for simulation

        auto simulate = [&](const string& name, auto pick_index)->void{
            string resultfile = string("result/result") + to_string(i) + string("_") + name + string(".txt");
            ofstream result(resultfile);
            if(!result.is_open()){
                cerr << "Could not open " << resultfile << " for writing." << endl;
                return;
            }
            result << name << " Scheduling Result for " << testfile << ":\n";

            linklist<Job> ready; // use your linklist as ready queue
            vector<string> timeline(MaxPH, "idle");
            int cpu_busy = 0;
            // tracking
            map<int,int> misses; // per task id
            map<int,int> completions;

            for(int t=0;t<MaxPH;++t){
                // release jobs
                for(auto &task: tasks){
                    if(t >= task.phase && ((t - task.phase) % task.period == 0)){
                        Job j;
                        j.tid = task.tid;
                        j.remaining = task.execution_time;
                        j.exec_time = task.execution_time;
                        j.release_time = t;
                        j.period = task.period;
                        j.abs_deadline = t + (task.relative_deadline>0?task.relative_deadline:task.period);
                        ready.push_back(j);
                    }
                }

                if(ready.empty()){
                    timeline[t] = "idle";
                    continue;
                }

                // pick job index according to policy
                int pick = pick_index(ready, t);
                // fetch job by index
                int idx = 0;
                Job cur;
                for(auto it = ready.begin(); it != ready.end(); ++it, ++idx){
                    if(idx == pick){ cur = *it; break; }
                }

                // execute 1 unit
                cur.remaining -= 1;
                cpu_busy++;
                timeline[t] = string("T") + to_string(cur.tid);

                // update the node in list: we must replace by erasing and reinserting if remaining>0
                if(cur.remaining <= 0){
                    // completed: remove from ready and record
                    int rem_idx = pick;
                    // check deadline
                    if(t+1 > cur.abs_deadline) misses[cur.tid]++;
                    else completions[cur.tid]++;
                    ready.erase(rem_idx);
                } else {
                    // update remaining: replace node's data
                    // find node and set remaining
                    int uidx = 0;
                    for(auto it = ready.begin(); it != ready.end(); ++it, ++uidx){
                        if(uidx == pick){
                            // mutate through iterator->data
                            it.operator->()->data.remaining = cur.remaining;
                            break;
                        }
                    }
                }

                // optional: check deadlines of waiting jobs (record misses if any job already missed before getting CPU)
                int check_idx = 0;
                for(auto it = ready.begin(); it != ready.end(); ++it, ++check_idx){
                    Job j = *it;
                    if(t+1 > j.abs_deadline){
                        misses[j.tid]++;
                        // remove missed job
                        ready.erase(check_idx);
                        // after erasure, iterator invalid; restart scan
                        check_idx = -1;
                    }
                }
            }

            // write timeline
            for(int t=0;t<MaxPH;++t){
                result << t << ": " << timeline[t] << "\n";
            }
            result << "\nSummary:\n";
            result << "CPU busy time: " << cpu_busy << " / " << MaxPH << "\n";
            int total_misses = 0, total_comp = 0;
            for(auto &p: completions) total_comp += p.second;
            for(auto &p: misses) total_misses += p.second;
            result << "Completions: " << total_comp << "\n";
            result << "Misses: " << total_misses << "\n";
            result.close();
        };

    // pick_index implementations for EDF, RM, StrictLST
    // We'll write pickers using std::function with known Job type
        auto pick_idx_edf = [&](linklist<Job>& ready, int now)->int{
            int best = -1; int idx=0; int best_dead = INT_MAX;
            for(auto it = ready.begin(); it!=ready.end(); ++it, ++idx){
                Job j = *it;
                if(j.abs_deadline < best_dead){ best_dead = j.abs_deadline; best = idx; }
            }
            return best;
        };
        auto pick_idx_rm = [&](linklist<Job>& ready, int now)->int{
            int best=-1; int idx=0; int best_period = INT_MAX;
            for(auto it=ready.begin(); it!=ready.end(); ++it, ++idx){
                Job j = *it;
                if(j.period < best_period){ best_period = j.period; best = idx; }
            }
            return best;
        };
        auto pick_idx_slack = [&](linklist<Job>& ready, int now)->int{
            int best=-1; int idx=0; int best_slack = INT_MAX;
            for(auto it=ready.begin(); it!=ready.end(); ++it, ++idx){
                Job j = *it;
                int slack = (j.abs_deadline - now) - j.remaining;
                if(slack < best_slack){ best_slack = slack; best = idx; }
            }
            return best;
        };

        // Because simulate expects a pick_index callable of signature (linklist<Job>&, int)->int,
        // we'll wrap them with std::function
        simulate("edf", [&](linklist<Job>& r, int now){ return pick_idx_edf(r, now); });
        simulate("rm", [&](linklist<Job>& r, int now){ return pick_idx_rm(r, now); });
        simulate("sl", [&](linklist<Job>& r, int now){ return pick_idx_slack(r, now); });
    }

    return 0;
}
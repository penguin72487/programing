#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        // int n = nums.size();
        int ans = 0;
        // int i_Op = 0;
        {
            auto it = lower_bound(nums.begin(), nums.end(), goal);
            auto jt = upper_bound(nums.begin(), nums.end(), goal);
            ans += distance(it, jt)+1;
            if(jt!=nums.end()) ans--;
        }
        for(auto i= ++nums.begin(); i!=nums.end(); i++){
            auto it = lower_bound(i, nums.end(), *i+goal);
            auto jt = upper_bound(i, nums.end(), *i+goal);
            ans += distance(it, jt)+1;
            if(jt!=nums.end()) ans--;
        }

        return ans;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    Solution s;
    vector<int> nums = {0,0,0,0,0};
    int goal = 0;
    cout << s.numSubarraysWithSum(nums, goal) << endl;
    nums = {1,0,1,0,1};
    goal = 2;
    cout << s.numSubarraysWithSum(nums, goal) << endl;
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
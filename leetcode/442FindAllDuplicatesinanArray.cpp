#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) {
                ans.push_back(abs(nums[i]));
            }
            nums[idx] = -nums[idx];
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
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = s.findDuplicates(nums);
    for(auto x: ans) cout << x << " ";
    cout << endl;
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
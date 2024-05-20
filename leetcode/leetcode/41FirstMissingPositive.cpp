#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = 0;
            }
        }
        for (int i = 0 ; i < n; ++i)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for(int i = 1; i <= n; i++) {
            if(nums[i] != i) return i;
        }
        return n + 1;
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
    vector<int> nums = {1,2,0};
    cout << s.firstMissingPositive(nums) << endl;
    
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
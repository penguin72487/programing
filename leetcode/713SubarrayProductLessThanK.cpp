#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        int ans = 0;
        for(int i = 0, j = 0, prod = 1; j < n; j++) {
            prod *= nums[j];
            while(prod >= k) {
                prod /= nums[i++];
            }
            ans += j - i + 1;
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
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << s.numSubarrayProductLessThanK(nums, k) << endl;
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
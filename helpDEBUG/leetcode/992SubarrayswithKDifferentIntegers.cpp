#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int ans = 0;
        for(int l = 0, r = 0; r < n; r++){
            freq[nums[r]]++;
            while(freq.size() > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            if(freq.size() == k){
                ans+=r-l;
            }
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
    Solution sol;
    vector<int> nums = {1,2,1,3,4};
    int k = 3;
    cout<<sol.subarraysWithKDistinct(nums, k)<<endl;

    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
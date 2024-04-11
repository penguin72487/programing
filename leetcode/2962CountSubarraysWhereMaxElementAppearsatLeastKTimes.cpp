#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int target = *max_element(nums.begin(), nums.end());
        int ans=0;
        for (int l = 0, r = 0,cnt=0; r < n;r++)
        {
            if(nums[r]==target){
                cnt++;
            }
            if(cnt<k){

            }
            else{
                while(cnt>=k){
                    ans+=n-r;
                    if(nums[l]==target){
                        cnt--;
                    }
                    l++;
                }
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
    Solution s;
    vector<int> nums = {1, 3, 2,3 , 3};
    int k = 2;
    cout << s.countSubarrays(nums, k) << endl;


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
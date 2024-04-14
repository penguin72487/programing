#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int countZero = count(nums.begin(), nums.end(), 0);
        if(countZero>1){
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        int product = 1;
        for(auto x: nums){
            if(x!=0){
                product *= x;
            }
        }
        vector<int> ans;
        for(auto x: nums){
            if(x==0){
                ans.push_back(product);
            }
            else if(countZero==1){
                ans.push_back(0);
            }
            else{
                ans.push_back(product/x);
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
    vector<int> nums = {1,2,3,4};
    vector<int> ans = s.productExceptSelf(nums);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& it:nums)
        {
            it*=it;
        }
        sort(nums.begin(),nums.end());
        return nums;
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
    vector<int> num = {-4,-1,0,3,10};
    for(auto i:s.sortedSquares(num))
        cout<<i<<" ";
    cout<<endl;



    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
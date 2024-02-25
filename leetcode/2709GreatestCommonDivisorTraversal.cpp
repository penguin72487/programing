#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {

        map<int, set<int>> mis;
        for(auto i:nums){
            for(int j=1; j*j<=i; j++){
                while(i%j==0){
                    i/=j;
                    if(i%j!=0){
                        mis[j].insert(i);
                        mis[i].insert(j);
                    }
                }
                
            }
        }
        int odd = 0;
        // int even = 0;
        for(auto i:mis){
            if((i.second.size()&1)&&i.second.size()>1){
                odd++;
            }
            // else{
            //     even++;
            // }
        }
        if(odd!=0 && odd!=2){
            return 0;
        }

        return 1;
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
    vector<int> nums = {3,9,5};
    cout << s.canTraverseAllPairs(nums);

#ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
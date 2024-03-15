#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(1e5+1,0);
        for(auto &i:nums)
        {
            freq[i]++;
        }
        int max_freq = *max_element(freq.begin(), freq.end());
        int ans = 0;
        for(int i=0;i<1e5+1;i++)
        {
            if(freq[i]==max_freq)
            {
                ans++;
            }
        }
        return ans*max_freq;
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
    vector<int> nums = {1,2,2,3,1,4};
    cout<<s.maxFrequencyElements(nums)<<endl;


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
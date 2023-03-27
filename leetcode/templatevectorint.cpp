#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        for(auto& i:arr)
        {
            for (int j = count; j < i;++j)
            {
                
            }
        }
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    int totalTrips = 5;
    vector<int> num = {2,3,4,7,11};
    cout<<s.findKthPositive(num,totalTrips)<<"\n";
    return 0;
}
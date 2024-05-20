#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dif=arr[1]-arr[0];
        for(auto it=next(arr.begin()); it!=arr.end();++it)
        {
            if(*prev(it)+dif!=*it)
            {
                return 0;
            }
        }
        return 1;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {3,5,1};
    cout<<s.canMakeArithmeticProgression(num);
}
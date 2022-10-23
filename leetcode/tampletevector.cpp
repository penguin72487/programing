#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& num) {
        sort(num.rbegin(), num.rend());
        for (int i = 2,n=num.size();i<n;++i) {
            if(num[i-2]<num[i-1]+num[i])
            {
                return num[i - 2] + num[i - 1] + num[i];
            }
        }

            return 0;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {2,1,2};
    cout<<s.largestPerimeter(num);
}
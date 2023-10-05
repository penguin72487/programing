#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> num(n+1);
        num[0]=0;
        num[1]=1;
        int m = (n + 1)>>1;
        for(int i=1;i<m;++i)
        {
                num[i<<1]=num[i];
                num[i<<1|1]=num[i]+num[i+1];

        }
        return *max_element(num.begin(),num.end());
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    cout<<s.getMaximumGenerated(7);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int MOD = 1000000007;
    vector<int> seg;
    int n;
    int sumSubarrayMins(vector<int>& arr) {
        n=arr.size();
        seg.resize(n);

        fill(seg.begin(), seg.end(), 1 << 30);
        seg.insert(seg.end(),arr.begin(),arr.end());
        for (int i = n - 1; i > -1;--i){
            seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
        }
        int  sum = 0;
        for (int i = 1;i <=n;++i){
            for (int j = 0; j+i <=n;++j)
            {
                sum  = (sum+query(j, j + i))%MOD;
                //sum %= MOD;
            }
        }
        return sum;
    }
    int query(int l,int r) //[l,r)
    {
        int res = 1 << 30;
        for (l+=n,r+=n; l < r;l>>=1,r>>=1)
        {
            if(l&1)
            {
                res =min(res,seg[l++]);
            }
            if(r&1)
            {
                res = min(res, seg[--r]);
            }
        }
        return res;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {3, 1, 2, 4};
    cout<<s.sumSubarrayMins(num);
    return 0;
}
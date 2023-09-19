#include<bits/stdc++.h>
using namespace std;
tuple<bool,vector<int>> table(vector<int> vt, int n)
{
    
    bool flag = 0;
    if(n==0)
    {
        if(*min_element(vt.begin(),vt.end())==0)
            return {0,vt};
        else
            return {1,vt};
    }

    for (int i = n + 1; i<vt.size();i++)
    {
        if(vt[i-n-1]==0&&vt[i]==vt[i-n-1])
        {
            vector<int> v = vt;
            v[i] = n;
            v[i - n - 1] = n;
            auto [f,ans]=table(v,n-1);
            if(f)
            {
                flag = 1;
                return {flag,ans};
            }
            flag |= f;
        }
    }
    return {flag,vt};
}
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int t = 45;
    for(int i=1;i<=t;i++)
    {
        int n=i;
        //cin >> n;
        vector<int> v(n<<1,0);
        auto [flag,ans]=table(v,n);
        if(flag)
        {
            reverse(ans.begin(),ans.end());
            for(auto &it:ans)
                cout << it << " ";
            cout << "\n";
        }
        else
            cout << "0\n";
    }
    return 0;
}


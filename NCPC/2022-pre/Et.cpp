#include<bits/stdc++.h>
using namespace std;
tuple<bool,vector<int>> table(vector<int>& vt,set<int>& index, int n)
{
    
    bool flag = 0;
    if(n==0)
    {
        if(*min_element(vt.begin(),vt.end())==0)
            return {0,vt};
        else
            return {1,vt};
    }
    for (auto it = index.begin();it!=index.end();++it)
    {
        if(*it + n + 1 >*index.rbegin())
            break;
        auto jt = index.find(*it + n + 1);
        if(jt!=index.end())
        {
            vector<int> v = vt;
            set<int> indext = index;
            v[*it] = n;
            v[*jt] = n;
            indext.erase(*jt);
            indext.erase(*it);
            auto [f,ans]=table(v,indext,n-1);
            if(f)
            {
                flag = 1;
                return {flag,ans};
            }
            flag |= f;
            }
    }
    
    return {flag, vt};
}
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int t = 45;
    for (int i = 1; i <=t;++i)
    {
        cout << i << "\n";
        int n=i;
        vector<int> v(n<<1,0);
        set<int> index;
        for(int i=0;i<n<<1;i++)
        {
            index.insert(i);
        }
        auto [flag,ans]=table(v,index,n);
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


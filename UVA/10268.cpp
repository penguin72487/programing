#include<bits/stdc++.h>
using namespace std;
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int x;
    while(cin>>x)
    {
        
        cin.get();
        string s;
        getline(cin, s);
        cin.sync();
        
        stringstream ss(s);
        vector<long long> fomula;
        while(ss)
        {
            long long t;
            ss>>t;
            fomula.push_back(t);
        }
        fomula.pop_back();
        fomula.pop_back();
        //reverse(fomula.begin(), fomula.end());
        // if(x==0)
        // {
        //     cout << fomula[0]<<"\n";
        //     continue;
        // }
        int n = fomula.size();
        long long sum = 0;
        long long x1 = 1;
        for (int i = n - 1, j = 1; i >= 0;--i,++j)
        {
            sum += fomula[i] * j*x1;
            x1 *= x;
        }
            cout << sum << "\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    int t = 0;
    while(cin>>n)
    {
        if(t)
        {
            cout<<"\n";
        }
        ++t;
        cout<<"Case #"<<t<<": It is";
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        set<int> s;
        for (int i = 0;i<n-1;++i)
        {
            if(a[i]>=a[i+1])
            {
                cout<<" not a B2-Sequence.\n";
                goto endd;
            }
        }
        
        for (int i = 0;i<n;++i)
        {
            for (int j = i; j < n;++j)
            {
                if(s.find(a[i] + a[j])!=s.end())
                {
                    cout<<" not a B2-Sequence.\n";
                    goto end;
                }
                s.insert(a[i] + a[j]);
            }
        }
        cout << " a B2-Sequence.\n";
        end:;
        endd:;

    }
    return 0;
}
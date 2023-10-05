#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int x =a[n-1];
    vector<int> Xv(1,0);
    vector<int> Yv(1,0);
    for(auto it:a)
    {
        if(x%it==0)
        {
            if(Xv.back()==it)
            {
                Yv.push_back(it);
            }
            else
            {
                Xv.push_back(it);
            }
        }
        else
        {
            Yv.push_back(it);
        }
    }
    cout<<x<<" "<<Yv.back()<<"\n";
    return 0;
}
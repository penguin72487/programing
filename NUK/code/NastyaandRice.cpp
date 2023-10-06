#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int l = a - b;
        int r = a + b;
        int up = c + d;
        int down = c - d;
        bool flag = false;
        if(n*r>=down&&n*l<=up)
        {
            flag = true;
        }
        if(flag)
        {
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}
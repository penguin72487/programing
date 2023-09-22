#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    int n = 10;
    int v[n][n];
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < n;++j)
        {
            if(i==0||j==0||i==n-1||j==n-1)
                v[i][j] = 1;
            else if(i==1||j==1||i==n-2||j==n-2)
            {
                v[i][j] = 2;
            }
            else if(i==2||j==2||i==n-3||j==n-3)
            {
                v[i][j] = 3;
            }
            else if(i==3||j==3||i==n-4||j==n-4)
            {
                v[i][j] = 4;
            }
            else if(i==4||j==4||i==n-5||j==n-5)
            {
                v[i][j] = 5;
            }                
        }
    }
    while (t--)
    {
        long long ans = 0;
        char c;
        for(int i=0;i<n;++i)
        {
            for (int j = 0; j < n;++j)
            {
                cin >> c;
                if(c=='X')
                {
                    ans += v[i][j];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
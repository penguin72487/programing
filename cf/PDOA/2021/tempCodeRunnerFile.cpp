#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, t;
    cin>>n>>t;
    vector<vector<int>> a(n,vector<int>(n,0));
    bool celebrity[n];
    fill(celebrity, celebrity + n, 1);
    for(int i=0;i<t;i++){
        int node;
        cin>>node;
        int m;
        cin >> m;
        if(m==0)
        {
            cin >> m;
        }
        for (int j = 0; j < m;j++)
        {
            int x;
            cin >> x;
            a[node-1][x-1] = 1;
            celebrity[x-1] = 0;
        }
    }
    // for (int i = 0; i < n;i++)
    // {
    //     for (int j = 0; j < n;j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n;i++)
    {
        if(celebrity[i]==1)
        {
            continue;
        }
        for (int j = 0; j < n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(a[i][j]==1&&a[j][i]==1)
            {
                celebrity[j] = 1;
                celebrity[i] = 1;
                break;
            }
            else if(a[i][j]==0&&a[j][i]==0)
            {
                celebrity[j] = 1;
                celebrity[i] = 1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!celebrity[i]){
            cout << i + 1 << " ";
        }
    }

    
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            --a[i];
        }

        string s;
        cin>>s;

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='S')
            {
                q.push(i);
            }
        }
        int ans = 0;
        vector<int> vis(n, 0);
        while(!q.empty())
        {
            int it = q.front();
            q.pop();
            if(vis[it])
                continue;
            vis[it] = 1;
            if (s[it] == 'S'||s[it] == 'C')
            {
                q.push(a[it]);
                vis[a[it]]++;
            }
            else if(s[it] == 'P')
            {
                ans+=vis[it];
            }

        }
        cout<<ans<<endl;

    } 


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
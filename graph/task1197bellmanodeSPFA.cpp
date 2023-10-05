#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> dist(n,(1ll<<60));
    vector<long long> path_From(n,-1);
    dist[0] = 0;
    vector<vector<pair<int, long long>>> vec(n);
    int a, b;
    long long c;
    for (int i = 0;i < m; ++i)
    {
        cin >> a >> b >> c;
        vec[a-1].push_back(make_pair(b-1,c));

    }
    
    bool flag = 0;
    int u, v;
    long long d;
    int op=0;
    queue<int> q;
    for (int i = 0; i < n;++i)
    {
        q.push(i);
    }
    vector<int> count_Pass(n, 0);
    vector<int> passed(n, 1);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        if(count_Pass[now]>n)
        {
            flag = 1;
            op=now;
            break;
        }
        passed[now] = 0;
        ++count_Pass[now];
        for(auto it=vec[now].begin(); it != vec[now].end();++it)
        {
            u = now;
            v = it->first;
            d = it->second;
            if(dist[u]+d<dist[v])
            {
                //flag = 1;
                dist[v] = dist[u]+d;
                path_From[v] = u;
                op = v;
                if(passed[v]==0)
                {
                    q.push(v);
                    passed[v] = 1;
                }
            }
        }
        
    }
    
    if(flag)
    {
        
        vector<bool> pass_By(n,0);
        vector<int> ans;

        
        //int tmp = n - 1;
        int now = op;
        cout << "YES\n";
        //now = path_From[now];
        while(!pass_By[now])
        {
            //cout << now << "n\n";
            pass_By[now] = 1;
            ans.push_back(now+1);
            now = path_From[now];
        }
        //ans.push_back(op+1);
        cout << now+1 << " ";
        for(auto it=ans.rbegin(); it!=ans.rend();++it)
        {
            
            cout << *it << " ";
            if(*it==now+1)
            {
                break;
            }
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
    }


        return 0;
}
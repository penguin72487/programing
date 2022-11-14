#include<iostream>
#include<vector>
#include<tuple>
#include<unordered_map>
#include<map>
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
    vector<tuple<int, int, long long>> vec;
    queue<tuple<int, int, long long>> q;
    map<tuple<int, int, long long>, bool> pass;
    map<tuple<int, int, long long>, int> count_Pass;
    
    int a, b;
    long long c;
    for (int i = 0;i < m; ++i)
    {
        cin >> a >> b >> c;
        vec.push_back(make_tuple(a-1,b-1,c));
        q.push(vec.back());
        pass[vec.back()] = 1;
        count_Pass[vec.back()] = 1;
    }
    
    bool flag = 0;
    int u, v;
    long long d;
    int op=0;
    while(!q.empty())
    {
        if(count_Pass[q.front()]>n)
        {
            flag = 1;
            break;
        }
        tie(u, v, d) = q.front();
        pass[q.front()] = 0;
        q.pop();

        if(dist[u]+d<dist[v])
        {
            //flag = 1;
            dist[v] = dist[u]+d;
            path_From[v] = u;
            op = v;
            if(pass[make_tuple(u,v,d)]==0)
            {
                q.push(make_tuple(u, v, d));
                ++count_Pass[vec.back()];
                pass[make_tuple(u, v, d)]=1;
            }
            
        }
        
    }
    
    if(flag)
    {
        
        vector<bool> pass_By(n,0);
        vector<int> ans;

        
        int now = op;
        cout << "YES\n";
        while(!pass_By[now])
        {
            //cout << now << "n\n";
            pass_By[now] = 1;
            ans.push_back(now+1);
            now = path_From[now];
        }
        ans.push_back(now+1);
        if(ans[0]==now+1)
        {
            for(auto it=ans.rbegin(); it!=ans.rend();++it)
            {
                cout << *it << " ";
            }
        }
        else {
            for(auto it=ans.rbegin(); it!=ans.rend();++it)
            {
                cout << *it << " ";
                if(*it ==now+1)
                {
                    break;
                }
            }
            cout << "\n";
        }

    }
    else {
        cout << "NO\n";
    }


        return 0;
}
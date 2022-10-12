#include<iostream>
#include<vector>
#include<tuple>
#include<unordered_map>
#include<map>

using namespace std;
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> dist(n,(1ll<<60));
    vector<long long> path_From(n,-1);
    dist[0] = 0;
    vector<tuple<int, int, long long>> vec;
    int a, b;
    long long c;
    map<tuple<int, int, long long>,int> count;
    for (int i = 0;i < m; ++i)
    {
        cin >> a >> b >> c;
        vec.push_back(make_tuple(a-1,b-1,c));
        count[vec.back()] = 0;
    }
    
    bool flag = 0;
    int u, v;
    long long d;
    for (int i = 0; i < (n << 1); ++i)
    {   
        flag = 0;
        for(auto it = vec.begin();it != vec.end();++it)
        {
            tie(u, v, d) = *it;
            if(dist[u]+d<dist[v])
            {
                flag = 1;
                dist[v] = dist[u]+d;
                ++count[*it];
                path_From[v] = u;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    
    if(flag)
    {
        
        vector<bool> pass_By(n,0);
        vector<int> ans;
        int op=0;
        //int tmp = n - 1;
        for(auto it=vec.begin(); it != vec.end();++it)
        {
            if(count[*it]==n)
            {
                op = get<0>(*it);
                break;
            }
        }
        
        int now = op;
        cout << "YES\n";
        while(!pass_By[now])
        {
            //cout << now << "n\n";
            pass_By[now] = 1;
            ans.push_back(now+1);
            now = path_From[now];
        }
        ans.push_back(op+1);
        for(auto it=ans.rbegin(); it!=ans.rend();++it)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
    }


        return 0;
}
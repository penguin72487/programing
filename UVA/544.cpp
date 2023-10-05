#include<bits/stdc++.h>
using namespace std;
bool dfs(string op,string ed,map<string,vector<pair<string, int>>>& spsi_Map,map<string, int>& si_Map)
{
    //map<string, int> si_Map;//passed
    si_Map[op] = 1;
    if(op==ed)
    {
        return 1;
    }
    bool flag = 0;
    for(auto& it:spsi_Map[op]){
        if(si_Map.find(it.first)==si_Map.end()){
            //si_Map[it.first] = 1;
            flag |=dfs(it.first, ed, spsi_Map, si_Map);
        }
    }
    return flag;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    int k=0;
    while(cin>>n>>m)
    {
        ++k;
        if(n==0&&n==m)
        {
            break;
        }
        set<tuple<int, string, string>> s_Iss;

        map<string,vector<pair<string, int>>> spsi_Map;
        //set<string> ss;
        string s, t;
        int a;
        for(int i=0;i<m;i++)
        {
            cin >> s >> t>>a;
            s_Iss.insert({a,s, t});
        }
        string op, ed;
        cin >> op >> ed;
        
        for(auto it=s_Iss.rbegin();it!=s_Iss.rend();++it)
        {
            auto [a, s, t] = *it;
            spsi_Map[s].push_back({t, a});
            spsi_Map[t].push_back({s, a});
            // ss.insert(s);
            // ss.insert(t);
            map<string, int> tttt;
            if(dfs(op,ed,spsi_Map,tttt))
            {
                cout << "Scenario #" << k << "\n"
                     << a << " tons\n";
                break;
            }

        }

    }
    return 0;
}
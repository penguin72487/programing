#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
#include<queue>
#include <set>
using namespace std;
bool kick(int now,set<int> being,vector<int> path, set<int> teacher[]);
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,m;
    cin >> n>>m;
    set<int> teacher[n+1];
    for (int i = 0; i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        teacher[a].insert(b);
    }
    for(int i = 1; i<n;++i)
        if (teacher[i].size() != 0) {
            set<int> being;
            vector<int> path;
            if(kick(i,being,path,teacher)==0)
            {
                cout << "-1\n";
            }

            break;
        }
}
bool kick(int now,set<int> being,vector<int> path, set<int> teacher[])
{
    if(being.find(now) != being.end())
    {
        vector<int> ans;
        for(auto it=path.rbegin();*it!=now;++it)
        {
            ans.push_back(*it);
        }
        cout << ans.size() + 1 << "\n"
             << now;
        for(auto it=ans.rbegin();it!=ans.rend();++it)
        {
            cout <<" "<< *it;
        }
        return 1;
    }
    being.insert(now);
    path.push_back(now);
    for(auto it=teacher[now].begin();it!=teacher[now].end();++it)
    {
        if(kick(*it,being,path,teacher)==1)
        {
            return 1;
        }
    }

    return 0;
}
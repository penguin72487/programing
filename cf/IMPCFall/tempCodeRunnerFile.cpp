#include <iostream>
#include <list>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int x, k, y;
    cin >> x >> k >> y;
    list<int> power;
    for(int i = 0,tmp; i < n; ++i)
    {
        cin >> tmp;
        power.push_back(tmp);
    }
    list<int> war;
    set<int> war_Set;
    for(int i = 0,tmp; i < m; ++i)
    {
        cin >> tmp;
        war.push_back(tmp);
        war_Set.insert(tmp);
    }
    war.push_back(2147483647);

    long long ans = 0;
    auto i_War = war.begin();
    int last_Target = 0;
    while(!power.empty())
    {
        list<int> kill_Line;
        int target=*i_War;
        ++i_War;

        war_Set.erase(target);
        for(auto it=power.begin(); it!=power.end();it=power.begin())
        {
            if(*it==target)
            {
                power.pop_front();
                break;
            }
            else if(war_Set.find(*it)!=war_Set.end())
            {
                cout << "-1\n";
                return 0;
            }
            kill_Line.push_back(*it);
            power.pop_front();
        }
        if(kill_Line.size()==0)
        {
            last_Target=target;
            continue;
        }
        else if(kill_Line.size()>=k)
        {
            while(kill_Line.size()>=k)
            {
                ans += x;
                auto iit = kill_Line.begin();
                for (int i = 0; i < k;++i)
                {
                    ++iit;
                }
                    
                kill_Line.erase(kill_Line.begin(),iit);
            }
        }
        if(kill_Line.size()<k)
        {
            int max_Item = *(max_element(kill_Line.begin(), kill_Line.end()));
            if(max_Item>target&&max_Item>last_Target)
            {
                cout << "-1\n";
                return 0;
            }
            else {
                ans+=kill_Line.size()*y;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
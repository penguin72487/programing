#include<iostream>
#include<queue>
#include<deque>
#include<set>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    deque<int> store;
    //int dp[n];
    priority_queue<int> k_Big;
    for (int i = 0; i < n;++i)
    {
        int tmp;
        cin >> tmp;
        store.push_back(tmp);
    }
    for (auto it = store.begin(); it != store.end();++it)
    {
        set<int> re_I;
        re_I.insert(*it);
        deque<int> t_store;
        t_store = store;
        while(!t_store.empty())
        {
            if(re_I.find(t_store.front())==re_I.end())
            {
                re_I.insert(t_store.front());
                t_store.pop_front();
                continue;
            }
            break;

        }
        k_Big.push(re_I.size());
        //dp[i] = re_I.size();
    }
    int ans = 0;
    for (int i = 0; i < k;++i)
    {
        cout << k_Big.top()<< " ";
        ans += k_Big.top();
        k_Big.pop();
    }
    cout << ans << "\n";
}
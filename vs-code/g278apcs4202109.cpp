#include<iostream>
#include<queue>
#include<set>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    int store[n];
    //int dp[n];
    priority_queue<int> k_Big;
    for (int i = 0; i < n;++i)
    {
        cin >> store[i];
    }
    for (int i = 0; i < n;++i)
    {
        set<int> re_I;
        re_I.insert(store[i]);
        for (int j = i+1; j < n;++j)
        {
            if(re_I.find(store[j])==re_I.end())
            {
                re_I.insert(store[j]);
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
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
bool cmp(int a,int b)
{
    return (a > b);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int cost[n];
    fill(cost,cost+n,0);
    for (int i = 0; i < k;++i)
    {
        int a, b,h;
        cin >> a >> b>>h;
        for (int i = a - 1; i < b;++i)
        {
            cost[i] += h;
        }
    }
    sort(cost,cost+n);

    priority_queue<int> list;

    long long ans = 0;
    int tmp;
    for (int i = 0; i < n;++i)
    {
        cin >> tmp;
        list.push(tmp);
       
    }
    //sort(list, list + n);
    for (int i = 0; i < n;++i)
    {
        ans+=list.top()*cost[i];
        list.pop();
    }
    cout << ans << "\n";
}
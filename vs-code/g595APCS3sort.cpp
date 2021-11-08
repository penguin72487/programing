#include<iostream>
#include<algorithm>
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
    sort(cost,cost+n,cmp);
    int list[n];
    long long ans = 0;
    for (int i = 0; i < n;++i)
    {
        cin >> list[i];
        ans+=list[i]*cost[i];
    }
    cout << ans << "\n";
}
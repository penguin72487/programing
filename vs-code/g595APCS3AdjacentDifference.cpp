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
    int Cost[n];
    fill(Cost,Cost+n,0);
    for (int i = 0; i < k;++i)
    {
        int a, b,h;
        cin >> a >> b>>h;
        Cost[a-1] += h;
        Cost[b] -= h;
    }
    //int cost[n];
    for (int i_Sum=0,i = 0; i < n;++i)
    {
        i_Sum += Cost[i];
        Cost[i] = i_Sum;
        
    }
    sort(Cost, Cost + n, cmp);
    int list[n];
    
    long long ans = 0;
    for (int i = 0; i < n;++i)
    {
        cin >> list[i];
       
    }
    sort(list, list + n);
    for (int i = 0; i < n;++i)
    {
        ans+=list[i]*Cost[i];
    }
    cout << ans << "\n";
}
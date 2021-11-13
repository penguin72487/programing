#include<iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n;++i)
    {
        cin >> list[i];
    }
    int ans = 0;
    if(list[0]==0)
    {
        list[0] = list[1];
        ans += list[0];
    }
    if(list[n-1]==0)
    {
        list[n - 1] = list[n - 2];
        ans += list[n - 1];
    }
    for (int i = 1; i < n;++i)
    {
        if(list[i]==0)
        {
            list[i] = min(list[i-1],list[i+1]);
            ans += list[i];
        }
    }
    cout << ans << "\n";
}
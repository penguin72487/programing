#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int max = -INT_MAX;
    int min = INT_MAX;
    int ans = 0;
    for (int j = 0,i; j < n;j++)
    {
        cin >> i;
        if(i > max)
        {
            max = i;
            ans++;
        }
        if(i < min)
        {
            min = i;
            ans++;
        }
    }
    cout << ans-2 << endl;
    return 0;
}
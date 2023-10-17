#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int coin[] = {1, 5, 10, 20, 100};
    int ans = 0;
    for(int i=4; i>=0; --i)
    {
        if(n>=coin[i])
        {
            ans += n/coin[i];
            n %= coin[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
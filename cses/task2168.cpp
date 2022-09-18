#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;

    int ans_P[n];
    fill(ans_P, ans_P+n,0);
    int ans_S[n];
    fill(ans_S, ans_S+n,0);
    int lest=2147483647;
    int rest=0;
    for(int i = 0,a_Cash,b_Cash; i < n; ++i)
    {
        cin >> a_Cash >> b_Cash;
        if(a_Cash<=lest&&b_Cash>=rest)
        {
            ans_P[i] = 1;
        }
        if (a_Cash >=lest &&b_Cash<=rest)
        {
            ans_S[i] = 1;
        }
        lest = min(lest, a_Cash);
        rest = max(rest, b_Cash);
    }
    for(int i=0;i<n; ++i)
    {
        cout << ans_P[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n; ++i)
    {
        cout << ans_S[i] << " ";
    }
    cout << "\n";

    return 0;
}

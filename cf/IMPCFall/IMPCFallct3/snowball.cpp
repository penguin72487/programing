#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int w, h;
    int e, r, t, y;
    cin >> w >> h >> e >> r >> t >> y;
    int ans = w;
    if(r<y)
    {
        swap(r, y);
        swap(e, t);
    }
    ans += (r + h) * (h - r + 1) / 2;
    ans -= e;
    if(ans<0)
    {
        ans = 0;
    }
    ans += (r + y-1) * (r - y) / 2;
    ans -= t;
    if(ans<0)
    {
        ans = 0;
    }
    if(y>1)
    {
        ans += (y) * (y - 1) / 2;
    }
    cout << (ans < 0 ? 0 : ans) << "\n";

    return 0;
}
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
class step{
public:
    int i_X;
    int i_Y;
    step ()
    {

    }
    step(int t_X,int t_Y)
    {
        i_X = t_X;
        i_Y = t_Y;
    }
    bool operator()(step val,step val2)
    {
        return (val.i_Y<val2.i_Y);
    }
    
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    set<int> cost;
    cost.insert(0);
    cost.insert(m);
    step cut[n];
    for (int i = 0; i < n;++i)
    {
        cin >> cut[i].i_X >> cut[i].i_Y;
    }
    sort(cut, cut + n, step());
    for (int i = 0; i < n;++i)
    {
        cost.insert(cut[i].i_X);
        auto it = cost.find(cut[i].i_X);
        ans += *next(it) - *prev(it);
    }
    cout << ans << "\n";
}
#include <iostream>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    int lvl_Max = (int)log2(n)+1;
    int sp[lvl_Max][n];

    for(int i=0;i<n;i++)
    {
        cin>>sp[0][i];
    }
    for(int lvl=1;lvl<lvl_Max;lvl++)
    {
        for(int i=0;i+(1<<(lvl-1))<n;i++)
        {
            sp[lvl][i] = min(sp[lvl-1][i],sp[lvl-1][i+(1<<(lvl-1))]);
            
        }
    }
    for(int i=0;i<q;i++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int lvl = log2(r - l + 1);
        cout << min(sp[lvl][l],sp[lvl][r-(1<<lvl)+1])<<"\n";
    }
}

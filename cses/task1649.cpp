#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int seg_T[(n<<1)];
    fill(seg_T, seg_T + n, 2147483647);
    for (int i = 0; i < n;++i)
    {
        cin>>seg_T[n+i];
    }
    for(int i=n-1; i>0;--i)//build
    {
        seg_T[i] = min(seg_T[(i << 1)], seg_T[(i << 1) | 1]);
    }

    while(q-->0)
    {
        int type;
        cin >> type;
        if(type ==1)
        {
            int k, u;
            cin >> k >> u;
            --k;
            seg_T[n+k]=u;
            for (int i_Now = n + k; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)] = min(seg_T[i_Now ^ 1], seg_T[i_Now]);
            }
        }
        else 
        {
            int a, b;
            cin >> a >> b;
            int ans = 2147483647;
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    ans = min(ans, seg_T[i_op++]);
                }
                if (i_ed & 1)
                {
                    ans = min(ans, seg_T[--i_ed]);
                }
                
            }
            cout << ans << "\n";
        }
    }
}
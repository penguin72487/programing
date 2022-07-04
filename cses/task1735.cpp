#include <iostream>
#include<numeric>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    long long seg_T[(n<<1)];
    fill(seg_T, seg_T + n, 0);
    for (int i = 0; i < n;++i)
    {
        cin>>seg_T[n+i];
    }
    adjacent_difference(seg_T + n, seg_T + (n << 1), seg_T + n);
    for(int i=n-1; i>0;--i)//build
    {
        seg_T[i] = seg_T[(i << 1)] + seg_T[(i << 1) | 1];
    }

    while(q-->0)
    {
        int type;
        cin >> type;
        if(type ==1)
        {
            int a, b,u;
            cin >> a>>b >> u;
            seg_T[n+a-1]=u;
            for (int i_Now = n + a-1; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)] = min(seg_T[i_Now ^ 1], seg_T[i_Now]);
            }

            if(b!=n)
            {
                seg_T[n + b] -= u;
                for (int i_Now = n + b; i_Now; i_Now >>= 1)
                {
                    seg_T[(i_Now >> 1)] = min(seg_T[i_Now ^ 1], seg_T[i_Now]);
                }
            }
        }
        else if(type == 2)
        {
            int a, b,x,u;
            cin >> a>>b >> x;
            long long sum_A = 0;
            for (int i_op = n, i_ed = n + a; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    sum_A +=seg_T[i_op++];
                }
                if (i_ed & 1)
                {
                    sum_A += seg_T[--i_ed];
                }
                
            }
            u = x - sum_A;
            seg_T[n+a-1]=u;
            for (int i_Now = n + a-1; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)] = min(seg_T[i_Now ^ 1], seg_T[i_Now]);
            }

            if(b!=n)
            {
                seg_T[n + b] -= u;
                for (int i_Now = n + b; i_Now; i_Now >>= 1)
                {
                    seg_T[(i_Now >> 1)] = min(seg_T[i_Now ^ 1], seg_T[i_Now]);
                }
            }
        }
        else 
        {
            int a, b;
            cin >> a >> b;
            long long sum_A = 0;
            long long sum_B = 0;
            for (int i_op = n, i_ed = n + a; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    sum_A +=seg_T[i_op++];
                }
                if (i_ed & 1)
                {
                    sum_A += seg_T[--i_ed];
                }
                
            }
            for (int i_op = n, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    sum_B +=seg_T[i_op++];
                }
                if (i_ed & 1)
                {
                    sum_B += seg_T[--i_ed];
                }
                
            }
            cout << sum_B-sum_A << "\n";
        }
    }
}
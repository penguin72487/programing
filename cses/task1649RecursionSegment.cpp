#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Segment_Tree{
    public:
        int n;//i_op
        vector<long long> seg_T;
        Segment_Tree(vector<long long> &seg)
        {
            n=seg.size()-1;
            seg_T.resize((n<<2));
            fill(seg_T.begin(), seg_T.end(),((1ull<<63)-1ull));

            build(1,1,n,seg);
        }
        void build(int i_Now,int tL,int tR,vector<long long> &seg)
        {
            if(tL==tR)
            {
                seg_T[i_Now] = seg[tL];
            }
            else
            {
                int mid=(tL+tR)>>1;
                build((i_Now << 1),tL,mid,seg);
                build((i_Now << 1) + 1, mid + 1, tR,seg);
                seg_T[i_Now] = min(seg_T[i_Now << 1], seg_T[(i_Now << 1) +1]);
            }
        }

        void update(int i_Now,int leafL,int leafR,int k,int u)
        {
            if(leafL==leafR)
            {
                seg_T[i_Now] = u;
            }
            else
            {
                if(k<=(leafL+leafR)>>1)
                {
                    update((i_Now << 1),leafL ,((leafL + leafR) >> 1),  k, u);
                }
                else
                {
                    
                    update((i_Now << 1) | 1, ((leafL + leafR) >> 1) + 1, leafR, k, u);
                }
                seg_T[i_Now] = min(seg_T[i_Now << 1], seg_T[(i_Now << 1) | 1]);
            }

        }
        long long query(int i_Now,int leafL,int leafR,int a,int b)
        {
            if(a<=leafL&&leafR<=b)
            {
                return seg_T[i_Now];
            }
            else if(a>leafR||leafL>b)
            {
                return ((1ull<<63)-1ull);
            }
            else
            {
                return min(query((i_Now << 1) | 1, ((leafL + leafR) >> 1) + 1, leafR, a, b), query(i_Now << 1, leafL, (leafR + leafL) >> 1, a, b));
            }
        }
        void update(int k, int u)
        {
            --k;
            seg_T[n+k]=u;
            for (int i_Now = n + k; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)] = min(seg_T[i_Now ^ 1], seg_T[i_Now]);
            }

        }
        long long query(int a,int b)
        {
            
            long long ans = ((1ull<<63)-1ull);
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
            return ans;
        }
        
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> seg(n+1);
    for(auto it=next(seg.begin()); it!=seg.end();++it)
    {
        cin >> *it;
    }
    Segment_Tree seg_T(seg);

    while(q-->0)
    {
        int type;
        cin >> type;
        if(type ==1)
        {
            int k, u;
            cin >> k >> u;
            seg_T.update(k, u);
        }
        else 
        {
            int a, b;
            cin >> a >> b;
            cout <<seg_T.query(a, b) << "\n";
        }
    }
}
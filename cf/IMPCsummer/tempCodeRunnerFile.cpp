#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
class node
{
    public:
    long long val=0ll,tag=0ll,leaf=1ll;

};
class Segment_Tree{
    public:
        int n;//i_op
        vector<node> seg_T;
        Segment_Tree(vector<node> &seg)
        {
            n=seg.size();
            seg_T.resize(n);
            for(int i=0; i<n; i++)
            {
                seg_T.push_back(seg[i]);
            }
            for(int i=n-1; i>0;--i)//build
            {
                seg_T[i].leaf = seg_T[(i << 1)].leaf + seg_T[(i << 1) | 1].leaf;
            }
        }
        void apply_Tag(int i_Now,long long u)
        {
            if(i_Now<n)
            {
                seg_T[i_Now].tag=u;
            }
            else
            {
                    seg_T[i_Now].val = u;
                
            }
        }
        void rang_Pull(int a,int b){
            for (int h = log2(n),i_op = n +a-1,i_ed=n+b; h;--h)
            {
                for(int i=i_op>>h;i<=(i_ed>>h);++i)
                {
                    if(seg_T[i].tag)
                    {
                        apply_Tag(i<<1,seg_T[i].tag);
                        apply_Tag(i<<1|1,seg_T[i].tag);
                        seg_T[i].tag = 0;
                    }
                }
            }

        }
        void rang_Set(int a,int b,long long u)// tracks of point increment aka modify
        {
            if(a>b)
            {
                return;
            }
            rang_Pull(a, a);
            rang_Pull(b, b);
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    apply_Tag(i_op++,u);
                }
                if (i_ed & 1)
                {
                    apply_Tag(--i_ed,u);
                }
                
            }
            //rang_Push(a,a);
            //rang_Push(b,b);

        }
        long long query(int a,int b)
        {
            rang_Pull(a, a);
            rang_Pull(b, b);
            long long ans = 0;
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    ans += seg_T[i_op].val;
                    ++i_op;
                }
                if (i_ed & 1)
                {
                    --i_ed;
                    ans += seg_T[i_ed].val;
                    
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
    vector<node> seg(n);
    Segment_Tree seg_T(seg);
    int query[q][3];
    for (int i = q-1; i >-1;--i)
    {
        cin >> query[i][0] >> query[i][1]>> query[i][2];
    }
    for (int i = 0; i < q;++i)
    {
        seg_T.rang_Set(query[i][0], query[i][2]-1, query[i][2]);
        seg_T.rang_Set(query[i][2]+1, query[i][1], query[i][2]);
    }
        //seg_T.rang_Pull(1, n);
        for (int i = 0; i < n; i++)
        {
            cout << seg_T.seg_T[n + i].val << " ";
        }
}
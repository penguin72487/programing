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
                seg_T[i].val = seg_T[(i << 1)].val+seg_T[(i << 1) | 1].val;
                seg_T[i].leaf = seg_T[(i << 1)].leaf + seg_T[(i << 1) | 1].leaf;
            }
        }
        void update(int k, long long u)// one point update
        {
            --k;
            seg_T[n+k].val=u;
            for (int i_Now = n + k; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)].val = seg_T[i_Now ^ 1].val + seg_T[i_Now].val;
            }

        }
        void apply_Tag(int i_Now,long long u)
        {
            seg_T[i_Now].val += u*seg_T[i_Now].leaf;
            if(i_Now<n)
            {
                seg_T[i_Now].tag+=u;
            }
        }
        void push(int i_Now)// update change up to father and grand grand... aka build
        {
            for (int i_op = i_Now + n; i_op;i_op>>=1)
            {
                seg_T[i_Now>>1].val=seg_T[i_Now].val + seg_T[i_Now^1].val;
            }
        }
        void pull(int i_Now)// pull tag down to child aka push 
        {

            for (int h = log2(n) ; h;--h)
            {
                for(int i_op = n + i_Now,i=i_op>>h;i==(i_op>>h);++i)
                {
                    if(seg_T[i].tag)
                    {
                        apply_Tag(i<<1,seg_T[i].tag);
                        apply_Tag(i<<1|1,seg_T[i].tag);
                        //seg_T[i].val += seg_T[i_Now].tag;
                        seg_T[i].tag = 0;
                    }
                }
            }
        }
        void rang_Inc(int a,int b,long long u)// tracks of point increment aka modify
        {
            pull(a-1);
            pull(b);
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
            push(a-1);
            push(b);

        }
        long long query(int a,int b)
        {
            pull(a-1);
            pull(b);
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
    for(auto it=seg.begin(); it!=seg.end();++it)
    {
        cin >> it->val;
    }
    Segment_Tree seg_T(seg);

    while(q-->0)
    {
        int type;
        cin >> type;

        if(type ==1)
        {
            int a,b, u;
            cin >> a >> b >> u;
            seg_T.rang_Inc(a, b, u);
        }
        else 
        {
            int k;
            cin >> k;
            cout << seg_T.query(k, k) << "\n";
        }
    }
}
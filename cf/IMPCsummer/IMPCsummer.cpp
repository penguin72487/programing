#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
class node
{
    public:
    long long val=0ll,tag=0ll,set=0ll,leaf=1ll;
 
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
        
        void push(int i_Now)// update change up to father and grand grand... aka build
        {
            if(i_Now>=(n<<1))
            {
                return;
            }
            for (int i_op = i_Now; i_op;i_op>>=1)
            {
                seg_T[i_op>>1].val=seg_T[i_op].val + seg_T[i_op^1].val;
            }
        }
        void calc(int i_Now) // update change up to father
        {
            if(i_Now<n)
            {
                seg_T[i_Now].val = seg_T[i_Now << 1].val+seg_T[(i_Now << 1) | 1].val;
            }
        }
        void rang_Push(int a,int b)//clear
        {
            for(int i_op= n + a - 1, i_ed = n + b-1; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                for (int i = i_ed; i >= i_op; --i)
                {
                    calc(i);
                }
            }
        }
        void apply_Tag(int i_Now,long long u)
        {
            if(i_Now>=(n<<1))
            {
                return;
            }
            seg_T[i_Now].val += u*seg_T[i_Now].leaf;
            if(i_Now<n)
            {
                seg_T[i_Now].tag+=u;
            }
            push(i_Now);
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
                        apply_Tag((i<<1)|1,seg_T[i].tag);
                        //seg_T[i].val += seg_T[i_Now].tag;
                        seg_T[i].tag = 0;
                    }
                    else if(seg_T[i].set)
                    {
                        apply_Set(i << 1, seg_T[i].set);
                        apply_Set((i << 1)|1, seg_T[i].set);
                        seg_T[i].set = 0;
                    }
                }
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
                        apply_Tag((i<<1)|1,seg_T[i].tag);
                        seg_T[i].tag = 0;
                    }
                    else if(seg_T[i].set)
                    {
                        apply_Set(i << 1, seg_T[i].set);
                        apply_Set((i << 1)|1, seg_T[i].set);
                        seg_T[i].set = 0;
                    }
                    push(i);
                }
            }
 
        }
        
        void rang_Inc(int a,int b,long long u)// tracks of point increment aka modify
        {
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
            //push(a-1);
            //push(b);
 
        }
        void apply_Set(int i_Now,long long u)
        {
            if(i_Now>=(n<<1))
            {
                return;
            }
            seg_T[i_Now].val = u*seg_T[i_Now].leaf;
            if(i_Now<n)
            {
                seg_T[i_Now].set = u;
            }
            //push(i_Now);
        }
        void rang_Set(int a,int b,long long u)// tracks of point increment aka modify
        {
            rang_Pull(a, a);
            rang_Pull(b, b);
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    apply_Set(i_op++,u);
                }
                if (i_ed & 1)
                {
                    apply_Set(--i_ed,u);
                }
                
            }
            //push(a-1);
            //push(b);
 
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
    for(auto it=seg.begin(); it!=seg.end();++it)
    {
        cin >> it->val;
    }
    Segment_Tree seg_T(seg);
    int last_Type=-1;
    while(q-->0)
    {
        int type;
        cin >> type;
 
        if(type ==1)
        {
            int a,b, u;
            cin >> a >> b >> u;
            if(last_Type !=1)
            {
                //seg_T.rang_Pull(1,n);
                //seg_T.rang_Push(a,b);
                last_Type = 1;
            }
 
            seg_T.rang_Inc(a, b, u);
        }
        else if(type ==2)
        {
            int a,b,u;
            cin >> a >> b >> u;
            if(last_Type!=2)
            {
                //seg_T.rang_Pull(1,n);
                //seg_T.rang_Push(a, b);
                last_Type = 2;
            }
            seg_T.rang_Set(a,b,u);
        }
        else 
        {
            int a, b;
            cin >> a >> b;
            cout << seg_T.query(a,b) << "\n";
        }
    }
}
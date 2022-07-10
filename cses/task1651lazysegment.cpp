#include <iostream>
#include <vector>
using namespace std;
class node{
public:
    long long val = 0ll, tag = 0ll;
    node()
    {

    }
};
class Segment_Tree{
    public:
        int n;//i_op
        vector<node> seg_T;
        Segment_Tree(vector<node> &seg)
        {
            n=seg.size()-1;
            seg_T.resize((n << 2));

            build(1,1,n,seg);
        }
        void build(int i_Now,int tL,int tR,vector<node> &seg)
        {
            if(tL==tR)
            {
                seg_T[i_Now].val = seg[tL].val;
            }
            else
            {
                int mid=(tL+tR)>>1;
                build((i_Now << 1),tL,mid,seg);
                build((i_Now << 1) + 1, mid + 1, tR,seg);
                seg_T[i_Now].val = seg_T[i_Now << 1].val + seg_T[(i_Now << 1) + 1].val;
            }
        }
        void add(int i_Now, int tL,int tR,int a,int b,long long u)
        {
            if(a<=tL&&tR<=b)
            {
                seg_T[i_Now].tag += u;
                return;
            }
            else if(a>tR||tL>b)
            {
                return;
            }
            push(i_Now);
            int mid=(tL+tR)>>1;
            add(i_Now<<1,tL,mid,a,b,u);
            add((i_Now << 1)+1, mid+ 1, tR, a, b, u);
            pull(i_Now, tL, tR);
        }
        void push(int i_Now)//push tag to child
        {
            seg_T[i_Now<<1].tag += seg_T[i_Now].tag;
            seg_T[(i_Now<<1)|1].tag += seg_T[i_Now].tag;
            seg_T[i_Now].tag = 0;
        }
        void pull(int i_Now, int tL, int tR) // update val from child
        {
            int mid=(tL+tR)>>1;
            seg_T[i_Now].val=sum(i_Now<<1,tL,mid)+sum((i_Now<<1)+1,mid+1,tR);
        }
        long long sum(int i_Now,int tL,int tR)// retunr val + tag 
        {
            return seg_T[i_Now].val + seg_T[i_Now].tag * (tR - tL + 1);
        }
        long long query(int i_Now,int tL,int tR,int a,int b)
        {
            if(a<=tL&&tR<=b)
            {
                return sum(i_Now,tL,tR);
            }
            else if(a>tR||tL>b)
            {
                return 0ll;
            }
            else
            {
                push(i_Now);

                
                int mid=(tL+tR)>>1;
                long long ret =query(i_Now<<1,tL,mid,a,b)+query((i_Now<<1)+1,mid+1,tR,a,b);
                pull(i_Now, tL, tR);
                return ret;
            }
        }
        
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<node> seg(n+1);
    for(auto it=next(seg.begin()); it!=seg.end();++it)
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
            seg_T.add(1, 1, n, a, b, u);
        }
        else 
        {
            int k;
            cin >> k;
            cout << seg_T.query(1, 1, n, k, k) << "\n";
        }
    }
}
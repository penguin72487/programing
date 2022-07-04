#include <iostream>
#include <vector>
using namespace std;
class node{
    public:
        long long val=0, tag=0;
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
            n=seg.size();
            seg_T.resize(n);
            //fill(seg_T.begin(), seg_T.end(),0);
            for(int i=0; i<n; i++)
            {
                seg_T.push_back(seg[i]);
            }
            
            for(int i=n-1; i>0;--i)//build
            {
                seg_T[i].val = seg_T[(i << 1)].val+seg_T[(i << 1) | 1].val;
            }
        }
        void update(int a,int b,int u)
        {
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    if(i_op <n)
                    {
                        seg_T[i_op].tag+=u;
                        //int i_Now = i_op;
                        int count_Node=count_chi(i_op);
                        update(i_op, seg_T[i_op].val + seg_T[i_op].tag * count_Node);
                    }
                    else
                    {
                        update(i_op, seg_T[i_op].val + u);
                    }
                    

                    ++i_op;
                }
                if (i_ed & 1)
                {
                    --i_ed;
                    if(i_ed <n)
                    {
                        seg_T[i_ed].tag+=u;
                        //int i_Now = i_ed;
                        int count_Node=count_chi(i_ed);
                        update(i_ed, seg_T[i_ed].val + seg_T[i_ed].tag * count_Node);
                    }
                    else
                    {
                        update(i_ed, seg_T[i_ed].val + u);
                    }
                }
                
            }
            

        }
        void update(int k, int u)
        {
            seg_T[k].val=u;
            for (int i_Now = k; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)].val = seg_T[i_Now ^ 1].val+seg_T[i_Now].val;
            }

        }
        int count_chi(int i_Now)
        {
            for (int i = 1; ;++i)
            {
                if(((i_Now<<i)+(1<<i))>n)
                {
                    int count_Node = (1 << i) - 2; 
                    if((i_Now<<i)<n)
                    {
                        count_Node = n - (i_Now << i);
                    }
                    return count_Node;
                }
            }
        }

        long long query(int a,int b)
        {
            
            long long ans = 0;
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    ans =ans+ seg_T[i_op++].val;
                }
                if (i_ed & 1)
                {
                    ans = ans + seg_T[--i_ed].val;
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
        if(type ==1)// increases
        {
            int a,b, u;
            cin >> a>>b >> u;
            seg_T.update(a, b, u);
        }
        else if(type ==2) //set
        {
            int a, b,x;
            cin >> a >> b>>x;
            //cout <<seg_T.query(a, b) << "\n";
        }
        else //sum 
        {
            int a, b;
            cin >> a >> b;
            cout<<seg_T.query(a, b) << "\n";
        }
    }
}
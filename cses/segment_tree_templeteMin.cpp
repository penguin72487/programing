#include <iostream>
#include <vector>
using namespace std;
class Segment_Tree{
    public:
        int n;//i_op
        vector<long long> seg_T;
        Segment_Tree(vector<long long> &seg)
        {
            n=seg.size();
            seg_T.resize(n);
            fill(seg_T.begin(), seg_T.end(),((1ull<<63)-1ull));
            for(int i=0; i<n; i++)
            {
                seg_T.push_back(seg[i]);
            }
            for(int i=n-1; i>0;--i)//build
            {
                seg_T[i] = min(seg_T[(i << 1)], seg_T[(i << 1) | 1]);
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
    vector<long long> seg(n);
    for(auto it=seg.begin(); it!=seg.end();++it)
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
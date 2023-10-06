#include <iostream>
#include <vector>
#pragma GCC optimize("O3")

using namespace std;
class Segment_Tree{
    public:
        int n;//i_op
        vector<long long> seg_T;
        Segment_Tree(vector<long long> &seg)
        {
            n=seg.size();
            seg_T.resize(n);
            fill(seg_T.begin(), seg_T.end(),0);
            for(int i=0; i<n; i++)
            {
                seg_T.push_back(seg[i]);
            }
            for(int i=n-1; i>0;--i)//build
            {
                seg_T[i] = seg_T[(i << 1)]^seg_T[(i << 1) | 1];
            }
        }
        long long query(int a,int b)
        {
            
            long long ans = 0;
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    ans = ans ^ seg_T[i_op++];
                }
                if (i_ed & 1)
                {
                    ans = ans ^ seg_T[--i_ed];
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

        int a, b;
        cin >> a >> b;
        cout <<seg_T.query(a, b) << "\n";

    }
}
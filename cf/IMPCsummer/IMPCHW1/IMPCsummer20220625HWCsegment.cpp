#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
class Segment_Tree{
public:
    vector<long long> v_A;
    int n;//index op 
    Segment_Tree(vector<long long> &a)
    {
        n=a.size();
        v_A.resize(n);
        fill(v_A.begin(), v_A.end(),0);
        for (auto it = a.begin();it!=a.end();++it){
            v_A.push_back(*it);
        }
        for(int i=0;i<n;++i){
            int id_now = n + i;
            while(id_now)
            {
                 v_A[(id_now>>1)] = min(v_A[((id_now>>1)*2)],v_A[((id_now>>1)*2)+1]);
                id_now>>=1;
            }
        }
    }
    long long  query(int l,int r)
    {
        int i_op = n+l-1;
        int i_ed = n+r;
        long long ans = 2147483647;
        while(i_op<i_ed)
        {
            
            if(i_op&1)
            {
                ans=min(v_A[i_op],ans);
                ++i_op;
                
            }
            if(i_ed&1)
            {
                
                 --i_ed;
                ans=min(v_A[i_ed],ans);
            }

            i_op >>= 1;
            i_ed >>= 1;
        }
        return ans;
    }
    void update(int index,int val)
    {
        v_A[n+index-1] = val;
        int id_now = n + index-1;
        while(id_now)
        {
            v_A[(id_now>>1)] = min(v_A[((id_now>>1)*2)],v_A[((id_now>>1)*2)+1]);
            id_now>>=1;
        }


    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,t;
    cin >> n >> t;
    vector<long long> v_A(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v_A[i];
    }
    Segment_Tree seg(v_A);
    while(t--)
    {
        int r, a, b;
        cin >> r >> a >> b;
        if(r==1)
        {
            seg.update(a,b);
        }
        else
        {
            cout<<seg.query(a,b)<<"\n";
        }
    }

}
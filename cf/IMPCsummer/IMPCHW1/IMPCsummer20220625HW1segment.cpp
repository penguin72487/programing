#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
class Segment_Tree{
public:
    vector<int> v_A;
    int n;//index op 
    Segment_Tree(vector<int> &a)
    {
        n=a.size();
        v_A.resize(n);
        fill(v_A.begin(), v_A.end(),2147483647);
        for (auto it = a.begin();it!=a.end();++it){
            v_A.push_back(*it);
        }
        for(int i=0;i<n;++i){
            int id_now=n+i;
            while(id_now)
            {
                v_A[(id_now>>1)] += v_A[n+i];
                id_now>>=1;
            }
        }
    }
    int query(int l,int r)
    {
        int i_op = l;
        int i_ed = r+1;
        int ans = 0;
        while(i_op<i_ed)
        {
            
            if(i_op&1)
            {
                ans += v_A[i_op];
                ++i_op;
                
            }
            if(i_ed&1)
            {
                
                 --i_ed;
                 ans += v_A[i_ed];
            }

            i_op >>= 1;
            i_ed >>= 1;
        }
        return ans;
    }
    void update(int index,int val)
    {
        v_A[n+index] = val;
        int id_now = n + index;
        while(id_now)
        {
            v_A[(id_now>>1)] = v_A[(id_now|1)]+v_A[(id_now&0)];
            id_now>>=1;
        }


    }
};
int main()
{
    int n,t;
    cin >> n >> t;
    vector<int> v_A(n);
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
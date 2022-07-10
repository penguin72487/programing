#include <iostream>
#include <algorithm>
#include<vector>
#include <numeric>
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
        v_A.push_back(0);
        for(int i=0;i<n;++i){
            int id_now = n + i;
            id_now>>=1;
            while(id_now)
            {
                v_A[(id_now)] = v_A[(id_now<<1)]+v_A[(id_now<<1)+1];
                id_now>>=1;
            }
        }
    }
    long long  query(int l,int r)
    {
        int i_op = n+l-1;
        int i_ed = n+r;
        long long ans = 0;
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
    void update(int a,int b,int u)
    {
        v_A[n+a-1] += u;
        
        int id_now = n + a-1;
        while(id_now)
        {
            v_A[(id_now)] = v_A[(id_now<<1)]+v_A[(id_now<<1)+1];
            id_now>>=1;
        }
        if(b!=n)
        {
            v_A[n+b] -= u;
            id_now = n + b;
            while(id_now)
            {
                v_A[(id_now)] = v_A[(id_now<<1)]+v_A[(id_now<<1)+1];
                id_now>>=1;
            }

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
    vector<long long> v_ad(n);
    adjacent_difference(v_A.begin(),v_A.end(),v_ad.begin());

    Segment_Tree seg(v_ad);
    while(t--)
    {
        int r, a, b,u;
        cin >> r;
        if(r==1)
        {
            cin >> a >> b >> u;
            seg.update(a,b,u);
        }
        else
        {
            int b;
            cin >> b;
            cout<<seg.query(1,b)<<"\n";
        }
    }

}
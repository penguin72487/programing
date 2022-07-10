#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Segment_Tree{
    public:
        int n;
        vector<long long> seg_B;
        Segment_Tree(vector<long long> &seg)
        {
            n=seg.size();
            seg_B.resize(n);
            fill(seg_B.begin(), seg_B.end(), 0);
            for(auto it=seg.begin(); it!=seg.end();++it){
                seg_B.push_back(*it);
            }
            for(int i=n-1; i>0; --i){//build
                bool a = (seg_B[i << 1]);
                bool b = (seg_B[(i << 1) | 1]);
                seg_B[i] = b & a;
            }//build

        }
        void update(int k,long long u){
            --k;
            seg_B[n + k]+=u;
            for (int i_Now = n + k; i_Now;i_Now>>=1)
            {
                bool a = (seg_B[i_Now]);
                bool b = (seg_B[i_Now^1]);
                seg_B[i_Now >> 1] = a & b;
            }
        }
        long long query(int a,int b)
        {
            long long ans = 1;
            for(int i_op=a+n-1,i_ed= n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if(i_op & 1)
                {
                    bool a = (seg_B[i_op++]);
                    ans &= a;
                }
                if(i_ed & 1)
                {
                    bool a = (seg_B[--i_ed]);
                    ans &= a;
                }
            }
            return ans;
        }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    vector<long long> v_X(n,0);//right
    vector<long long> v_Y(n,0);//down
    Segment_Tree seg_X(v_X);//right
    Segment_Tree seg_Y(v_Y);//down
    while(q--){
        int type;
        cin>>type;
        if(type ==1)
        {
            int x, y;
            cin >> x >> y;
            seg_X.update(y, 1);
            seg_Y.update(x, 1);
        }
        else if(type ==2)
        {
            int x, y;
            cin >> x >> y;
            seg_X.update(y, -1);
            seg_Y.update(x, -1);
        }
        else
        {
            int x1,y1;
            int x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ans = 0;
            ans|=seg_X.query(y1,y2);
            ans|=seg_Y.query(x1,x2);
            if(ans&1)
            {
                cout <<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }

    }

}
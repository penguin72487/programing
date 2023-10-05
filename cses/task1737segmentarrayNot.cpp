#include <iostream>
#include <vector>
#include<algorithm>
#include <map>
#include<set>
using namespace std;
//vector<int> update_Table;// update on what version usually whith call_Table
vector<int> call_Table;// what mean of the call
vector<int> father_Version; //val from what version
class node{
    public:
        map<int, long long> vl_Val;
        //void *copy_Index;
        node()
        {
            vl_Val[0] = 0;
        }
        long long &operator[](int i)
        {
            auto it = vl_Val.find(i);
            if(it!=vl_Val.end())
            {
                return vl_Val[i];
            }
            else
            {

                //vi_Ver.insert(i);
                int i_Now = i;
                while(vl_Val.find(i_Now) == vl_Val.end())
                {

                    i_Now = father_Version[i_Now];
                }              
                
                vl_Val[i] = vl_Val[i_Now];
                return vl_Val[i];
            }
            
        }
};
class Segment_Tree{
    public:
        int n;//i_op
        vector<node> seg_T;
        //vector<int> copy_Index;// copy from who
        Segment_Tree(vector<node> &seg)
        {
            //update_Table.push_back(0);
            call_Table.push_back(0);
            father_Version.push_back(0);
            n=seg.size();
            seg_T.resize(n);
            for(int i=0; i<n; i++)
            {
                seg_T.push_back(seg[i]);
                //seg_T.back().copy_Index = &copy_Index;
            }
            for(int i=n-1; i>0;--i)//build
            {
                //seg_T[i].copy_Index = &copy_Index;
                seg_T[i][0] = seg_T[(i << 1)][0]+seg_T[(i << 1) | 1][0];
            }
        }
        void update(int vt,int a, int u)
        {
            --vt;
            --a;
            int v=call_Table[vt];
            seg_T[n+a][v]=u;
            for (int i_Now = n + a; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)][v] = seg_T[i_Now ^ 1][v]+ seg_T[i_Now][v];
            }

        }
        long long query(int vt,int a,int b)
        {
            --vt;
            int v = call_Table[vt];
            long long ans = 0;
            for (int i_op = n + a - 1, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    ans += seg_T[i_op++][v];
                }
                if (i_ed & 1)
                {
                    ans += seg_T[--i_ed][v];
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
        cin >> it->vl_Val[0];
    }
    Segment_Tree seg_T(seg);

    while(q-->0)
    {
        int type;
        cin >> type;
        if(type ==1)
        {
            int v, a, u;
            cin >> v >> a >> u;
            seg_T.update(v, a, u);
        }
        else if(type ==2)
        {
            int v, a, b;
            cin >> v >> a >> b;
            cout <<seg_T.query(v,a,b) << "\n";
        }
        else
        {
            int k;
            cin >> k;
            --k;
            
            father_Version.push_back(call_Table[k]);
            
            father_Version.push_back(call_Table[k]);
            call_Table[k]=father_Version.size()-2;
            
            call_Table.push_back(father_Version.size()-1);
            //update_Table[k]=update_Table.size();
            //father_Version[update_Table[k]] = k;

            //update_Table.push_back(update_Table.size()+1);
            //call_Table[k]=call_Table[k];
        }
    }
}
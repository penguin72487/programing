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
        int index;
        int val;
        node(){

        }

};
class Segment_Tree{
    public:

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
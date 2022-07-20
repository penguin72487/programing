#include <iostream>
#include <vector>
#include<algorithm>
#include <map>
#include<set>
#include<cmath>
using namespace std;
//vector<int> update_Table;// update on what version usually whith call_Table
vector<int> call_Table;// what mean of the call
vector<int> father_Version; //val from what version
class node{
    public:
        //int index;
        long long val=0;
        node *l=nullptr;
        node *r=nullptr;
        node(){

        }
        node(int v_T)
        {
            val = v_T;
        }

};
class Segment_Tree{
    public:
        vector<node *>root;
        int n;
        vector<node> seg;
        Segment_Tree(vector<node> &seg_T)
        {
            root.push_back(new node(0));
            seg = seg_T;
            root[0]->l = build(2);
            root[0]->r = build(3);
    }
    node* build(int i_Now)
    {

        node *tmp = new node;
        if(i_Now<n)
        {
            tmp->l = build(i_Now<<1);
            tmp->r = build((i_Now<<1)|1);
        }
        else
        {
            tmp->val =seg[i_Now].val;
        }
        return tmp;
    }
    void update(int v,int a,int k)
    {
        root[v]->val=update_Pull(2,root[v]->l,a,k)+update_Pull(3,root[v]->r,a,k);
    }
    long long update_Pull(int i_Now,node* child,int a,int k)
    {
        int h = log2(n);
        if(i_Now==a)
        {
            child->val = k;
            return k;
        }
        else if(a>>(h-(int)log2(i_Now))==i_Now)
        {
            child->val =update_Pull(i_Now<<1,child->l,a,k)+update_Pull((i_Now<<1)|1,child->r,a,k);
        }
        else
        {
            return child->val;
        }
        return 0ll;
    }
    long long query(int v,int a,int b)
    {
        long long ans=0ll;

        return ans;
    }
    void copy_Back(int version){
        root.push_back(new node(root[version]->val));
        root.back()->l=root[version]->l;
        root.back()->r=root[version]->r;
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
        if(type ==1)
        {
            int v, a, u;
            cin >> v >> a >> u;
            --v;
            --a;
            seg_T.update(v, a, u);
        }
        else if(type ==2)
        {
            int v, a, b;
            cin >> v >> a >> b;
            --v;
            --a;
            --b;
            cout <<seg_T.query(v,a,b) << "\n";
        }
        else
        {
            int k;
            cin >> k;
            --k;
            seg_T.copy_Back(k);
        }
    }
}
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
    int h;
    vector<node> seg;
    Segment_Tree(vector<node> &seg_T)
    {
        root.push_back(new node(0));
        seg = seg_T;
        root[0]->l = build(2);
        root[0]->r = build(3);
        h = log2(n);
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

    ~Segment_Tree()
    {
        for(auto it=root.begin(); it!=root.end();++it)
        {
            dis_Node(*it);
        }
    }
    void dis_Node(node *& n_Now)
    {
        if(n_Now->l)
        {
            dis_Node(n_Now->l);
        }
        if(n_Now->r)
        {
            dis_Node(n_Now->r);
        }
        delete n_Now;
    }
    
    void update(int v,int a,int k)
    {
        root[v]->l = update_Pull(2, root[v]->l, a, k);
        root[v]->r=update_Pull(3,root[v]->r,a,k);
        root[v]->val=root[v]->l->val+root[v]->r->val;

    }
    node* update_Pull(int i_Now,node* child,int a,int k)
    {
        
        if(a>>(h-(int)log2(i_Now))==i_Now) // if now is a's father
        {
            node *tmp = new node;
            tmp->l=update_Pull(i_Now<<1,child->l,a,k);
            tmp->r=update_Pull((i_Now<<1)|1,child->r,a,k);
            tmp->val = sum_Point(tmp->l, tmp->r);
        }
        else if(i_Now==a)
        {
            node *tmp = new node(k);
            return tmp;
        }
        else if(i_Now>(a+n))
        {
            return nullptr;
        }
        else 
        {
            return child;
        }
        return 0ll;
    }
    long long sum_Point(node *l,node *r)
    {
        if(l||r)
        {
            if(l&&r)
            {
                return l->val + r->val;
            }
            else
            {
                return l? l->val : r->val;
            }
        }
        else
        {
            return 0ll;
        }
    }
    long long query(int v,int a,int b)
    {
        return query(1, root[v], a, b);
    }
    long long query(int i_Now,node* child,int a,int b)
    {
        int level = log2(i_Now);
        int high_Limit =i_Now<<(h-level);
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
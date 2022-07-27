#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
        long long index, pri;
        long long val, sum;
        node *l, *r;
        node(long long k, long long v) : index(k), pri(rand()), val(v), sum(v), l(nullptr), r(nullptr){
 
        }
        node(node* t): index(t->index), pri(t->pri), val(t->val), sum(t->sum), l(t->l), r(t->r){
 
        }
};
 
class Treap
{
public:
    vector<node *> root;
    int n=0;
    Treap()
    {
        root.push_back(new node(0,0));
    }
    void insert(long long v)
    {
        if(n)
        {
            node *node_tmp = new node(n, v);
            root[0]=merge(root[0], node_tmp);
          
        }
        else 
        {
            root[0]->val = v;
        }
        ++n;
        
    }
 
    long long get_Sum(node *t)
    {
        return t ? t->sum : 0ll;
    }
    void update(int v,int k,int u)
    {
        root[v]=update(root[v],k,u);
    }
    node* update(node* t,int k,long long u)
    {
        if(!t)
        {
            return nullptr;
        }
        node* new_Node= new node(t);
        if(t->index<k)
        {
            new_Node->r=update(t->r,k,u);
 
        }
        else if(t->index>k)
        {
            new_Node->l=update(t->l,k,u);
            
        }
        else //if(t->index==k)
        {
            //node* new_Node= new node(t);
            new_Node->val = u;
            
        }
        pull(new_Node);
        return new_Node;
 
    }
    long long query(int v,int l,int r)
    {
        
        node *a,*b,*c;
        split_By_Index(root[v], l - 1, a, b);
        split_By_Index(b, r, b, c);
        long long ans = get_Sum(b);
        root[v] = merge(a, merge(b, c));
        return ans;
    }
    void copy_Back(int k)
    {
        root.push_back(new node(root[k]));
    }
 
    private: void pull(node *t)
    {
        t->sum = t->val + get_Sum(t->l) + get_Sum(t->r);
    }
 
    private: node *merge(node * a,node * b)
    {
        if(!a || !b)
            return a ? a : b;
        if(a->pri > b->pri)
        {
            a->r=merge(a->r,b);
            pull(a);
            return a;
        }
        else
        {
            b->l=merge(a,b->l);
            pull(b);
            return b;
        }
 
    }
    private: void split_By_Index(node *t,int k,node *&a,node *&b)
    {
        if(!t)
        {
            a=b= nullptr;
            return;
        }
        if(t->index<=k)
        {
            a = t;
            
            split_By_Index(t->r,k,a->r,b);
            pull(a);
            
        }
        else
        {
            b = t;
            
            split_By_Index(t->l, k, a, b->l);
            pull(b);
            
        }
    }
};
 
 
 
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int t[n];
    Treap root;
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        root.insert(t[i]);
    }
 
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
            root.update(v, a, u);
        }
        else if(type ==2)
        {
            int v, a, b;
            cin >> v >> a >> b;
            --v;
            --a;
            --b;
            cout <<root.query(v,a,b) << "\n";
        }
        else
        {
            int k;
            cin >> k;
            --k;
            root.copy_Back(k);
        }
    }
    return 0;
}
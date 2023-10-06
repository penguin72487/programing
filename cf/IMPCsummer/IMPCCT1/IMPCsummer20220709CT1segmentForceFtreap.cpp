#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

class node{
    public:
        long long index, pri;

        long long val, min,tag,set;
        int sz;//size
        node *l, *r;
        node(long long k, long long v) : index(k), pri(rand()), val(v), min(v),tag(0ll),set(0ll),sz(1), l(nullptr), r(nullptr){

        }
};

class Treap
{
public:
    node *root = nullptr;
    int n=0;
    ~Treap()
    {
        dis_Treap(root);
    }

    void insert(long long v)
    {
        node *node_tmp = new node(n, v);
        root=merge(root, node_tmp);
        ++n;
    }

    long long get_Sum(node *t)
    {
        if(!t) return ((1ull <<63)-1ull);
        
        if(t->tag&&t->set)
        {
            return t->set + t->tag;
        }
        else if(t->tag)
        {
            return t->min+t->tag;
        }
        else if(t->set)
        {
            return t->set; 
        }
        return t->min;
    }
    
    long long get_Size(node* t)
    {
        return t ? t->sz : 0ll;
    }
    void rang_Inc(int a,int b,int u)
    {
        node *l,*r,*c;
        split_By_Index(root, a - 1, l,r);
        split_By_Index(r, b, r, c);
        apply_Tag(r, u);
        //r->min += u*r->sz;
        root = merge(l, merge(r, c));
    }
    void rang_Set(int a, int b, int u)
    {
        node *l,*r,*c;
        split_By_Index(root, a - 1, l,r);
        split_By_Index(r, b, r, c);
        apply_Set(r, u);
        //r->min += u*r->sz;
        root = merge(l, merge(r, c));
    }
    long long query(int l,int r)
    {
        
        node *a,*b,*c;
        split_By_Index(root, l - 1, a, b);
        split_By_Index(b, r, b, c);
        long long ans = get_Sum(b);
        
        root = merge(a, merge(b, c));
        return ans;
    }
    
    private: void pull(node *t)
    {
        t->min = min(t->val,min( get_Sum(t->l) , get_Sum(t->r)));
        t->sz = 1 + get_Size(t->l) + get_Size(t->r);
    }
    private: void push(node *t)
    {
        if(!t)
        {
            return;
        }
        if(t->tag&&t->set)
        {
            t->val = t->set;
            t->min = t->set;
            apply_Set(t->l,t->set);
            apply_Set(t->r,t->set);
            t->set = 0;
            t->val += t->tag;
            t->min += t->tag;
            apply_Tag(t->l,t->tag);
            apply_Tag(t->r,t->tag);
            t->tag = 0;
        }
        else if(t->tag)
        {
            t->val += t->tag;
            t->min += t->tag;
            apply_Tag(t->l,t->tag);
            apply_Tag(t->r,t->tag);
            t->tag = 0;
        }
        else if(t->set)
        {
            t->val = t->set;
            t->min = t->set;
            apply_Set(t->l,t->set);
            apply_Set(t->r,t->set);
            t->set = 0;
        }
    }
    private: void apply_Tag(node *t,long long tag)
    {
        if(!t)
        {
            return;
        }
        t->tag += tag;
        //t->min += t->sz * tag;
        //t->val += tag;
        //pull(t);
    }
    private: void apply_Set(node*t,long long set)
    {
        if(!t)
        {
            return;
        }
        t->set = set;     
        t->min = set;
        t->val = set;
   
        t->tag = 0;
        //pull(t);
    }
    private: node *merge(node * a,node * b)
    {
        if(!a || !b)
            return a ? a : b;
        if(a->pri > b->pri)
        {
            push(a);
            a->r=merge(a->r,b);
            pull(a);
            return a;
        }
        else
        {
            push(b);
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
            push(a);
            split_By_Index(t->r,k,a->r,b);
            pull(a);
            
        }
        else
        {
            b = t;
            push(b);
            split_By_Index(t->l, k, a, b->l);
            pull(b);
            
        }
    }
    private: void dis_Treap(node *root)
    {
        if(!root)
        {
            return;
        }
        dis_Treap(root->l);
        dis_Treap(root->r);
        delete root;

    }
    
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    srand(time(0));
    int i_Tmp;
    Treap root;
    for(int i=0; i<n; ++i)
    {
        cin>>i_Tmp;
        root.insert(i_Tmp);
    }
    cin >> q;
    cin.get();
    while(q-->0)
    {
        int type=0;
        //cin.sync();
        //cin.ignore();
        
        string s="";
        getline(cin, s);
        stringstream ss(s);
        //ss.str(s);
        int in[3];
        while(ss)
        {
            ss>>in[type++];
        }
        if(type ==4)
        {
            if(in[0]>in[1])
            {
                root.rang_Inc(in[0], n-1, in[2]);
                root.rang_Inc(0, in[1], in[2]);
            }
            else
            {
                root.rang_Inc(in[0], in[1], in[2]);
            }
            
            
        }
        else 
        {
            if(in[0]>in[1])
            {
                cout << min(root.query(in[0], n-1),root.query(0, in[1])) << "\n";
            }
            else
            {
                cout << root.query(in[0], in[1])<< "\n";
            }
            
        }
    }
}
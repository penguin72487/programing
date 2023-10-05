#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
        long long index, pri;

        long long val, sum,tag,set;
        int sz;//size
        node *l, *r;
        node(long long k, long long v) : index(k), pri(rand()), val(v), sum(v),tag(0ll),set(0ll),sz(1), l(nullptr), r(nullptr){

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
        if(!t) return 0;
        
        if(t->tag&&t->set)
        {
            return (t->set + t->tag)*t->sz;
        }
        else if(t->tag)
        {
            return t->sum+t->tag*t->sz;
        }
        else if(t->set)
        {
            return t->set*t->sz; 
        }
        return t->sum;
    }
    
    long long get_Size(node* t)
    {
        return t ? t->sz : 0ll;
    }
    void update(int k,int u)
    {
        node *a,*b,*c;
        split_By_Index(root, k - 1, a, b);
        split_By_Index(b,k,b,c);
        b->val = u;
        b->sum = u;
        root = merge(a,merge(b,c));
    }
    void rang_Inc(int a,int b,int u)
    {
        node *l,*r,*c;
        split_By_Index(root, a - 1, l,r);
        split_By_Index(r, b, r, c);
        apply_Tag(r, u);
        //r->sum += u*r->sz;
        root = merge(l, merge(r, c));
    }
    void rang_Set(int a, int b, int u)
    {
        node *l,*r,*c;
        split_By_Index(root, a - 1, l,r);
        split_By_Index(r, b, r, c);
        apply_Set(r, u);
        //r->sum += u*r->sz;
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
        t->sum = t->val + get_Sum(t->l) + get_Sum(t->r);
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
            t->sum = t->set*t->sz;
            apply_Set(t->l,t->set);
            apply_Set(t->r,t->set);
            t->set = 0;
            t->val += t->tag;
            t->sum += t->tag*t->sz;
            apply_Tag(t->l,t->tag);
            apply_Tag(t->r,t->tag);
            t->tag = 0;
        }
        else if(t->tag)
        {
            t->val += t->tag;
            t->sum += t->tag*t->sz;
            apply_Tag(t->l,t->tag);
            apply_Tag(t->r,t->tag);
            t->tag = 0;
        }
        else if(t->set)
        {
            t->val = t->set;
            t->sum = t->set*t->sz;
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
        //t->sum += t->sz * tag;
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
        t->sum = set * t->sz;
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
    long long get_Val(node *t)
    {
        if(!t)
            return 0ll;
        if(t->tag&&t->set)
        {
            return (t->set + t->tag)*t->sz;
        }
        else if(t->tag)
        {
            return t->val+t->tag;
        }
        else if(t->set)
        {
            return t->set; 
        }
        return t->val;
    }
    friend ostream &operator<<(ostream &s,Treap& ob)
    {
        ob.cout_Val(s,ob.root);
        return s;
    }
    private: void cout_Val(ostream &s,node* t)
    {
        if(!t)
        {
            return;
        }
        s << get_Val(t);
        cout_Val(s,t->l);
        cout_Val(s,t->r);
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

    while(q--)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            int a,b, u;
            cin >> a >> b >> u;
            --a;
            --b;
            root.rang_Inc(a,b,u);
            //cout << root << "\n";
        }
        else if(type ==2)
        {
            int a,b,u;
            cin >> a >> b >> u;
            --a;
            --b;
            root.rang_Set(a,b,u);
            //cout << root << "\n";
        }
        else
        {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            cout << root.query(a,b) << "\n";
            //cout << root << "\n";
        }
    }
    return 0;
}
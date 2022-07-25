#include<iostream>
using namespace std;
class node{
    public:
        long long index, pri;

        long long val, sum,tag;
        int sz;//size
        node *l, *r;
        node(long long k, long long v) : index(k), pri(rand()), val(v), sum(v),tag(0ll),sz(1), l(nullptr), r(nullptr){

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
        return t ? t->sum+t->tag*t->sz : 0ll;
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
        r->tag += u;
        //r->sum += u*r->sz;
        root = merge(l, merge(r, c));
    }
    long long query(int l,int r)
    {
        
        node *a,*b,*c;
        split_By_Index(root, l - 1, a, b);
        split_By_Index(b, r, b, c);
        //pull(b);
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
        if(t->tag ==0)
        {
            return;
        }
        t->val += t->tag;
        t->sum += t->tag * get_Size(t);
        if(t->l)
        {
            t->l->tag += t->tag;
        }
        if(t->r)
        {
            t->r->tag += t->tag;
        }
        t->tag = 0;
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
            int a, b,u;
            cin >> a >> b>>u;
            --a;
            --b;
            root.rang_Inc(a,b,u);
        }
        else if(type ==2)
        {
            int l;
            cin >> l;
            --l;
            cout << root.query(l,l) << "\n";
        }
    }
    return 0;
}
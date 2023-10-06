#include<iostream>
using namespace std;
class node{
    public:
        long long pri;

        long long val, sum;
        bool tag;
        int sz;//size
        node *l, *r;
        node(long long v) :pri(rand()), val(v), sum(v),tag(false),sz(1), l(nullptr), r(nullptr){

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
        node *node_tmp = new node(v);
        root=merge(root, node_tmp);
        ++n;
    }

    long long get_Sum(node *t)
    {
        return t ? t->sum : 0ll;
    }
    long long get_Size(node* t)
    {
        return t ? t->sz : 0ll;
    }

    void rang_Revers(int l,int r)
    {
        node *a,*b,*c;
        split_By_Size(root, r, b, c);
        split_By_Size(b, l-1, a, b);
        b->tag ^= 1;
        root = merge(a, merge(b,c));
    }
    long long query(int l,int r)
    {
        
        node *a,*b,*c;
        split_By_Size(root, r, b, c);
        split_By_Size(b, l-1, a, b);
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
        swap(t->l, t->r);

        //t->val += t->tag;
        //t->sum=get_Sum(t); 
        if(t->l)
        {
            t->l->tag^=1;
        }
        if(t->r)
        {
            t->r->tag^=1;
        }
        t->tag = 0;
    }
    private: void swap(node*&a, node*&b)
    {
        node *tmp = a;
        a = b;
        b = tmp;
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
    
    private: void split_By_Size(node *t,int k,node *&a,node *&b)
    {
        if(!t)
        {
            a=b= nullptr;
            return;
        }
        push(t);
        if(get_Size(t->l)+1<=k)
        {
            a = t;
            //push(a);
            split_By_Size(t->r,k-get_Size(t->l)-1,a->r,b);
            pull(a);
            
        }
        else
        {
            b = t;
            //push(b);
            split_By_Size(t->l, k, a, b->l);
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
            int a, b;
            cin >> a >> b;
            // --a;
            // --b;
            root.rang_Revers(a,b);
        }
        else if(type ==2)
        {
            int l,r;
            cin >> l>>r;
            // --l;
            // --r;
            cout << root.query(l,r) << "\n";
        }
    }
    return 0;
}
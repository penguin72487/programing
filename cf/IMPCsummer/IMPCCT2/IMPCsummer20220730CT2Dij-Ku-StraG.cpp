#include<iostream>
#include<set>
using namespace std;
class node{
    public:
        long long index, pri;
        long long val;
        node *l, *r;
        node(long long k, long long v) : index(k), pri(rand()), val(v), l(nullptr), r(nullptr){

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
    void swap_Node(int l,int r)
    {
        node* a,*b,*c,*d,*e;
        split_By_Index(root, l - 1, a, b);
        split_By_Index(b, l,b,c);
        split_By_Index(c,r-1,c,d);
        split_By_Index(d, r, d, e);
        swap(b->val,d->val);
        root=merge(a,merge(b, merge(c,merge(d,e))));
    }
    long long query(int i,int k)
    {
        //int ans;
        set<int> circle;
        for (int j = 0; j < k;++j)
        {
            i= get_Val_By_index(i-1, root);
            if(circle.find(i) == circle.end())
            {
                circle.insert(i);
            }
            else
            {
                
            }
            
        }
        return i;
           
    }   
    long long get_Val_By_index(int i,node* t)
    {
        if(t->index<i)
        {
            return get_Val_By_index(i, t->r);
        }
        else if(t->index>i)
        {
            return get_Val_By_index(i, t->l);
        }
        else {
            return t->val;
        }

    }

    void swap(long long &a,long long &b)
    {
        a^=b^=a^=b;
    }

    private: node *merge(node * a,node * b)
    {
        if(!a || !b)
            return a ? a : b;
        if(a->pri > b->pri)
        {
            a->r=merge(a->r,b);

            return a;
        }
        else
        {
            b->l=merge(a,b->l);

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

            
        }
        else
        {
            b = t;
            
            split_By_Index(t->l, k, a, b->l);
            
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
    Treap root;
    int t_cash;
    for (int i = 0; i < n;++i)
    {
        cin >> t_cash;
        root.insert(t_cash);
    }
    while(q--)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            long long l,r;
            cin >> l >> r;
            --l;
            --r;
            if(l>r)
            {
                root.swap(l, r);
            }

            root.swap_Node(l,r);
        }
        else
        {
            int i, k;
            cin >> i >> k;
            cout<<root.query(i,k)<<"\n";
        }
    }
}
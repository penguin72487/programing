#include<iostream>
using namespace std;
class treap{
    public:
        long long index, pri;
        long long val, sum;
        treap *l, *r;
        treap(long long k, long long v) : index(k), pri(rand()), val(v), sum(v), l(nullptr), r(nullptr){

        }
};
long long get_Sum(treap *t)
{
    return t ? t->sum : 0ll;
}
void pull(treap *t)
{
    t->sum = t->val + get_Sum(t->l) + get_Sum(t->r);
}
treap *merge(treap * a,treap * b)
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
void split_By_Index(treap *t,int k,treap *&a,treap *&b)
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
void dis_Treap(treap *root)
{
    if(!root)
    {
        return;
    }
    dis_Treap(root->l);
    dis_Treap(root->r);
    delete root;

}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int t[n];
    treap *root=nullptr;
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        treap *treap_Tmp=new treap(i,t[i]);
        root = merge(root, treap_Tmp);
    }

    while(q--)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            int k, u;
            cin >> k >> u;
            --k;
            treap *a,*b,*c;
            split_By_Index(root, k - 1, a, b);
            split_By_Index(b,k,b,c);
            b->val = u;
            b->sum = u;
            root = merge(a,merge(b,c));
        }
        else if(type ==2)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            treap *a,*b,*c;
            split_By_Index(root, l - 1, a, b);
            split_By_Index(b, r, b, c);
            cout << get_Sum(b) << "\n";
            root = merge(a, merge(b, c));
        }
    }
    dis_Treap(root);
    return 0;
}
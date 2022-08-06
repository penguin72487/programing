#include <iostream>
using namespace std;
class node{
public:
    long long pri;
    char name;
    int sz;//size
    node* l, *r;
    node(char t_Name): pri(rand()), name(t_Name),sz(1), l(nullptr), r(nullptr){

    }
};
class Treap{
public:
    int n;
    node *root;
    Treap():n(0),root(nullptr)
    {

    }
    ~Treap(){
        dis_Node(root);
    }
    void insert(char c)
    {
        node* ins_Node=new node(c);
        root= merge(root, ins_Node);
        ++n;
    }
    long long get_Size(node* t)
    {
        return t? t->sz : 0ll;
    }
    void cut_Back(int l,int r)
    {
        node* a,*b,*c;
        split_By_Size(root, r, b, c);
        split_By_Size(b, l - 1, a, b);
        root=merge(a,c);
        root = merge(root, b);
    }
    private: void pull(node* t)
    {
        t->sz = 1 + get_Size(t->l) + get_Size(t->r);
    }
    
    private: void split_By_Size(node *t,int k,node *&a,node *&b)
    {
        if(!t)
        {
            a=b= nullptr;
            return;
        }
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



    private: node* merge(node * a,node * b)
    {
        if(!a||!b)
            return a ? a : b;
        if(a->pri > b->pri)
        {
            a->r=merge(a->r,b);
            pull(a);
            return a;
        }
        else
        {
            b->l = merge(a, b->l);
            pull(b);
            return b;
        }
    }
    private: void dis_Node(node *t)
    {
        if(t)
        {
            if(t->l)
            {
                dis_Node( t->l );
            }
            cout << t->name;
            if(t->r)
            {
                dis_Node( t->r );
            }
            delete t;
        }
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string c_Cash;
    cin >> c_Cash;
    Treap root;
    for(auto it=c_Cash.begin(); it!=c_Cash.end();++it)
    {
        root.insert(*it);
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        root.cut_Back(a, b);
    }
}
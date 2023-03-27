#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        long long val, pri;
        node *l, *r;
        node(long long v) : val(v), pri(rand()),l(nullptr), r(nullptr){

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
        root = merge(root, node_tmp);
        ++n;
    }
    void erase(long long v)
    {
        node* now = root;
        while (now)
        {
            if (now->val == v)
            {
                root = merge(root, merge(now->l, now->r));
                delete now;
                --n;
                return;
            }
            else if (now->val < v)
            {
                now = now->r;
            }
            else
            {
                now = now->l;
            }
        }
    }
    // void update(int k,int u)
    // {
    
    // }
    void left_rotate(node *&t)
    {
        node *tmp = t->r;
        t->r = tmp->l;
        tmp->l = t;
        t = tmp;
    }
    void right_rotate(node *&t)
    {
        node *tmp = t->l;
        t->l = tmp->r;
        tmp->r = t;
        t = tmp;
    }
    
    // private: node* insert(node *now, node* t)
    // {
    //     if(!now)
    //     {
    //         return t;
    //     }
    //     if(now->val < t->val)
    //     {
    //         now->r = insert(now->r, t);
    //     }
    //     else
    //     {
    //         now->l = insert(now->l, t);
    //     }
    //     if(now->pri < t->pri)
    //     {
    //         if(now->l == t)
    //         {
    //             right_rotate(now);
    //         }
    //         else
    //         {
    //             left_rotate(now);
    //         }
    //     }
    //     return now;

    // }

    private: node *merge(node * a,node * b)
    {
        if(!a || !b)
            return a ? a : b;
        if(a->pri > b->pri)
        {
            if(b->val < a->val)
            {
                a->l = merge(a->l, b);
            }
            else
            {
                a->r = merge(a->r, b);
            }
            return a;
        }
        else
        {
            if(a->val < b->val)
            {
                b->l = merge(a, b->l);
            }
            else
            {
                b->r = merge(a, b->r);
            }
            return b;
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
    int n;
    cin >> n;
    int t[n];
    Treap root;
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        //cin >> t[i];
        root.insert(t[i]);
    }
    return 0;
}
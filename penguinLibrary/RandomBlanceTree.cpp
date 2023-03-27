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
        node* pre = nullptr;

        while(now)
        {
            if(now->val == v)
            {
                if (now->val == v)
                {
                    if(pre == nullptr)
                    {

                    }
                    else if(pre->l == now)
                    {
                        pre->l =nullptr;
                    }
                    else
                    {
                        pre->r = nullptr;
                    }
                    root = merge(root, merge(now->l, now->r));
                    delete now;
                    --n;
                    return;
                }
            }
            else if(now->val < v)
            {
                pre = now;
                now = now->r;
            }
            else
            {
                pre = now;
                now = now->l;
            }
        }

        // while (now)
        // {
        //     if (now->val == v)
        //     {
        //         root = merge(root, merge(now->l, now->r));
        //         delete now;
        //         --n;
        //         return;
        //     }
        //     else if (now->val < v)
        //     {
        //         now = now->r;
        //     }
        //     else
        //     {
        //         now = now->l;
        //     }
        // }
    }
    friend ostream& operator<<(ostream& os,Treap& t)
    {
        t.inorder(t.root);
        return os;
    }
    void inorder(node* now)
    {
        if(!now)
        {
            return;
        }
        inorder(now->l);
        cout << now->val << " ";
        inorder(now->r);
    }
    private :
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

    node *merge(node * a,node * b)
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
    void dis_Treap(node *root)
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
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int n=16;
    //cin >> n;
    int t[n];
    Treap root;
    srand(time(0));
    long long r=rand()%n;
    long long s = rand();
    for(int i = 0; i < n; i++)
    {
        t[i] = rand();
    }
    for(int i = 0; i < n; i++)
    {
        root.insert(t[i]);
    }
    cout<<r<<" "<<s<<"\n";
    for(int i = 0; i < n; i++)
    {
        cout << root << "\n";
        int tmp = (r*i+s) % n;
        root.erase(t[tmp]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    long long key; //
    long long priorty;
    long long size; //
    long long val; //
    long long sum=0ll; //
    node* l=nullptr;
    node* r=nullptr;
    node(long long t_K,long long t_V):key(t_K),val(t_V),priorty(rand()),size(0),l(nullptr),r(nullptr){}
    node()
    {

    }
    node *merge(node* a,node* b){
            if(!a||!b)
            {
                return a ? a : b;
            }
            if(a->priorty>b->priorty)
            {
                a->r = merge(a->r, b);
                return a;
            }
            else
            {
                b->l = merge(a, b->l);
                return b;
            }

        }
        void split_By_Key(node *t, long long int k, node *&a,node*&b)
        {
            if(!t)
            {
                a=b=nullptr;
                return;
            }
            if(t->key<=k)
            {
                a = t;
                split_By_Key(t->r, k, a->r, b);
            }
            else
            {
                b = t;
                split_By_Key(t->l, k, a, b->l);
            }
        }
        void split_By_Size(node *t, long long int k, node *&a,node*&b)
        {
            if(!t){
                a = b = nullptr;
            }
            else if(get_Size(t->l)+1<=k){
                a = t;
                split_By_Size(t->r, k-get_Size(t->l), a->r, b);
                pull(a);
            }
            else
            {
                b = t;
                split_By_Size(t->l,k,a,b->l);
                pull(b);
            }

        }
        long long get_Size(node* t)
        {
            return t?t->size : 0;
        }
        long long sum_Child(node *t)
        {
            return t ? t->sum;
        }
        void pull(node * t)
        {
            t->size = 1 + get_Size(t->l) + get_Size(t->r);
        }
        void insert(node * t,long long k)
        {
            node* a, *b;
            split_By_Key(t,k,a,b);
            a = merge(a, new node(k));
            t = merge(a, b);
        }
        void erase(node * t,long long k)
        {
            node *a, *b;
            split_By_Key(t,k,a,b);
            node *c;
            split_By_Size(a, get_Size(a) - 1, a, c);
            delete c;
            t=merge(a,b);
        }
        int k_Th(node * t,long long k){
            node *a,*b;
            split_By_Key(t,k-1,a,b);
            node *c;
            split_By_Size(b, 1, b, c);
            int ret = b->key;
            b=merge(b,c);
            t=merge(a,b);
            return ret;
        }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    node *root = new node;
    for(int i=0; i<n; i++)
    {

    }

    return 0;
}
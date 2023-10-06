#include<bits/stdc++.h>
using namespace std;

class node {
public:
    long long val, pri;
    node *l, *r;

    node(long long v) : val(v), pri(rand()), l(nullptr), r(nullptr) {
    }
};

class Treap {
public:
    node *root = nullptr;
    int n = 0;

    ~Treap() {
        dis_Treap(root);
    }

    void insert(long long v) {
        root = insert(root, new node(v));
        ++n;
    }

    void erase(long long v) {
        root = erase(root, v);
    }

    void print() {
        inorder(root);
        cout << "\n";
    }
    friend ostream &operator<<(ostream &out, Treap &t) {
        t.inorder(t.root);
        return out;
    }

private:
    void left_rotate(node *&t) {
        node *tmp = t->r;
        t->r = tmp->l;
        tmp->l = t;
        t = tmp;
    }

    void right_rotate(node *&t) {
        node *tmp = t->l;
        t->l = tmp->r;
        tmp->r = t;
        t = tmp;
    }

    void inorder(node *now) {
        if (!now) {
            return;
        }
        inorder(now->l);
        cout << now->val << " ";
        inorder(now->r);
    }

    node *insert(node *now, node *t) {
        if (!now) {
            return t;
        }
        if (now->val < t->val) {
            now->r = insert(now->r, t);
            if (now->pri < now->r->pri) {
                left_rotate(now);
            }
        } else {
            now->l = insert(now->l, t);
            if (now->pri < now->l->pri) {
                right_rotate(now);
            }
        }
        return now;
    }

    node *erase(node *now, long long v) {
        if (!now) {
            return nullptr;
        }
        if (now->val == v) {
            node *ret = merge(now->l, now->r);
            delete now;
            --n;
            return ret;
        } else if (now->val < v) {
            now->r = erase(now->r, v);
        } else {
            now->l = erase(now->l, v);
        }
        return now;
    }

    node *merge(node *a, node *b) {
        if (!a || !b) {
            return a ? a : b;
        }
        if (a->pri > b->pri) {
            a->r = merge(a->r, b);
            return a;
        } else {
            b->l = merge(a, b->l);
            return b;
        }
    }

    void dis_Treap(node *root) {
        if (!root) {
            return;
        }
        dis_Treap(root->l);
        dis_Treap(root->r);
        delete root;
    }
};

int main() {
    int n = 16;
    int t[n];
    Treap treap;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        t[i] = rand();
    }
    for(int i = 0; i < n; i++)
    {
        treap.insert(t[i]);
    }
    //cout<<r<<" "<<s<<"\n";
    random_shuffle(t, t + n);
    for(int i = 0; i < n; i++)
    {
        cout<<treap<<"\n";
        treap.erase(t[i]);
    }
    return 0;
}
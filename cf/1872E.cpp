#include<bits/stdc++.h>
using namespace std;
class segment{
    class node{
        public:
        int i_Val0=0;
        int i_Val1=0;
        int b_S=1;
        int lazy_Tag=0;// 1 means tag not push down to children
    };
    public:
    vector<node> tree;
    int n;
    segment(vector<int> &v, vector<int> &s)
    {
        n=v.size();
        tree.resize(n<<1);
        for(int i=0;i<n;i++)
        {
            auto &it=tree[i+n];
            it.b_S=s[i];
            if(s[i])
                it.i_Val1=v[i];
            else
                it.i_Val0=v[i];
        }
        for(int i=n-1;i>0;i--)
        {
            auto &it=tree[i];
            auto &l=tree[i<<1];
            auto &r=tree[i<<1|1];
            it.i_Val0=l.i_Val0^r.i_Val0;
            it.i_Val1=l.i_Val1^r.i_Val1;
            it.b_S=l.b_S^r.b_S;
        }
    }
    void apply(int p)// tage down change to range father
    {
        tree[p].lazy_Tag^=1;
        swap(tree[p].i_Val0,tree[p].i_Val1);
        tree[p].b_S^=1;
    }
    void push(int p)// tage down change to children
    {
        if(tree[p].lazy_Tag)
        {
            apply(p<<1);
            apply(p<<1|1);
            tree[p].lazy_Tag=0;
        }
        
    }
    void pull(int p)//update change up to father
    {
        for (int i_Op = p; i_Op;i_Op>>=1)
        {
            auto& it = tree[i_Op>>1];
            push(i_Op>>1);
            auto& l = tree[i_Op];
            auto &r = tree[i_Op^1];
            it.i_Val0 = l.i_Val0 ^ r.i_Val0;
            it.i_Val1 = l.i_Val1 ^ r.i_Val1;
 
        }
    }
 
    void modify(int l,int r)//[l,r)
    {
        // push(l+n);
        // push(r+n-1);
        for(int i_Op=l+n,i_Ed=r+n;i_Op<i_Ed;i_Op>>=1,i_Ed>>=1)
        {
            if(i_Op&1)
            {
                apply(i_Op);
                pull(i_Op);
                i_Op++;
            }
            if(i_Ed&1)
            {
                --i_Ed;
                apply(i_Ed);
                pull(i_Ed);
            }
        }
        // pull(l+n);
        // pull(r+n-1);
 
    }
    void query(int b)
    {
        if(b)
            cout << tree[1].i_Val1<<" ";
        else
            cout << tree[1].i_Val0 << " ";
    }
 
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &it:v)
            cin >> it;
        string st;
        cin >> st;
        vector<int> s;
        for(auto &it:st)
            s.push_back(it=='1');
        
        segment seg(v,s);
        int q;
        cin >> q;
        while(q--)
        {
            int type;
            cin >> type;
            if(type==1)
            {
                int l, r;
                cin >> l >> r;
                l--;
                seg.modify(l,r);
            }
            else
            {
                int b;
                cin >> b;
                seg.query(b);
            }
        }
        cout << "\n";
        
    }
    return 0;
}
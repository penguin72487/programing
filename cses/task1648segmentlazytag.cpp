#include<bits/stdc++.h>
using namespace std;
class segment{
    class node{
        public:
            long long val = 0;
            long long lazy=0;
            long long leaf=1ll;
    };
    vector<node> tree;
    int n;
    public:
    segment(vector<long long>& a){
        n=a.size();
        tree.resize(n<<1);
        for(int i=0; i<n; ++i)
            tree[i+n].val=a[i];

        for(int i=n-1; i>0; --i)
        {
            tree[i].val=tree[i<<1].val+tree[i<<1|1].val;
            tree[i].leaf=tree[i<<1].leaf+tree[i<<1|1].leaf;
        }
            
    }
    void pull(int now)//pull up
    {
        for (int i_Op = now; i_Op;i_Op>>=1)
        {
            push(i_Op>>1);
            tree[i_Op>>1].val=tree[i_Op].val+tree[i_Op^1].val;
        }
    }
    void push(int now)//push down
    {
        if(now>=n)
            return;
        if(tree[now].lazy)
        {
            apply(now<<1,tree[now].lazy);
            apply(now<<1|1,tree[now].lazy);
            tree[now].lazy = 0;
        }
    }
    void apply(int now,int inc)
    {
        tree[now].lazy += inc;
        tree[now].val += inc*tree[now].leaf;
    }
    void modify(int l,int r,int inc)
    {
        for (int i_Op = l + n, i_Ed = r + n; i_Op < i_Ed;i_Op>>=1,i_Ed>>=1)
        {
            if(i_Op&1)
            {
                apply(i_Op,inc);
                pull(i_Op);
                i_Op++;
            }
            if(i_Ed&1)
            {
                --i_Ed;
                apply(i_Ed,inc);
                pull(i_Ed);
            }
        }
    }
    long long query(int l, int r) {
        // 推送懶人標記
        for (int i = l + n, j = r + n - 1; i > 1; i >>= 1, j >>= 1) {
            push(i >> 1);
            push(j >> 1);
        }

        long long res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res += tree[l].val;
                l++;
            }
            if (r & 1) {
                r--;
                res += tree[r].val;
            }
        }

        // 拉取節點值
        for (int i = l + n, j = r + n - 1; i > 1; i >>= 1, j >>= 1) {
            pull(i >> 1);
            pull(j >> 1);
        }

        return res;
    }

};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(auto &i:a)
        cin >> i;
    segment seg(a);
    while(q--)
    {
        int op;
        cin >> op;
        if(op==1)
        {
            int l, r, inc;
            cin >> l >> r >> inc;
            seg.modify(l - 1, r, inc);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l - 1, r) << '\n';
        }
    }
    return 0;
}
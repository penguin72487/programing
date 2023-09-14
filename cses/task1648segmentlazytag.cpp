#include<bits/stdc++.h>
using namespace std;
class segment{
    class node{
        public:
            long long val = 0;
            long long lazy=0;
    };
    vector<node> tree;
    int n;
    segment(vector<int>& a){
        n=a.size();
        tree.resize(n<<1);
        for(int i=0; i<n; ++i)
            tree[i+n].val=a[i];
    }
    void pull(int now)//pull up
    {
        tree[now].val=tree[now<<1].val+tree[now<<1|1].val;
    }
    void push(int now)//push down
    {
        if(tree[now].lazy)
        {
            tree[now<<1].lazy+=tree[now].lazy;
            tree[now<<1|1].lazy+=tree[now].lazy;
            tree[now].lazy = 0;
        }
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
    
    return 0;
}
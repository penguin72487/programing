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
    void apply(int now,long long& inc)
    {
        tree[now].lazy += inc;
        tree[now].val += inc*tree[now].leaf;
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
    void pull(int& now)//pull up
    {
        for (int i_Op = now; i_Op;i_Op>>=1)
        {
            push(i_Op>>1);
            tree[i_Op>>1].val=tree[i_Op].val+tree[i_Op^1].val;
        }
    }

    void modify(int l,int r,long long& inc)
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
    void pushPath(int& p) {
        for (int h = __lg(n); h > 0; h--) {
            int i = p >> h;
            push(i);
        }
    }
    long long query(int l, int r) {
        // 推送懶人標記
        

        long long res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                pushPath(l);
                res += tree[l].val;
                l++;
            }
            if (r & 1) {
                r--;
                pushPath(r);
                res += tree[r].val;
            }
        }
        return res;
    }

};
int main() {
    // 使用 ifstream 和 ofstream 進行檔案輸入/輸出
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, q;
    fin >> n >> q;
    vector<long long> a(n);
    for(auto &i : a)
        fin >> i;

    segment seg(a);
    while(q--) {
        int op;
        fin >> op;
        if(op == 1) {
            int l, r;
            long long inc;
            fin >> l >> r >> inc;
            seg.modify(l - 1, r, inc);
        } else {
            int l, r;
            fin >> l >> r;
            fout << seg.query(l-1, r) << "\n";
        }
    }

    fin.close();
    fout.close();

    // 檢查輸出結果是否與答案檔案相同
    ifstream f1("output.txt");
    ifstream f2("answer.txt");
    string s1, s2;
    bool isSame = true;
    while(getline(f1, s1) && getline(f2, s2)) {
        if(s1 != s2) {
            isSame = false;
            break;
        }
    }
    if(isSame && !f1.eof()) isSame = false; // 檢查 f1 是否還有其他行
    if(isSame && !f2.eof()) isSame = false; // 檢查 f2 是否還有其他行

    if(isSame) {
        cout << "Output matches the answer file!" << endl;
    } else {
        cout << "Output does not match the answer file." << endl;
    }

    f1.close();
    f2.close();

    return 0;
}
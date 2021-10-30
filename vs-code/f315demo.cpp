#include <iostream>
#define ll long long
using namespace std;
const int mxN = 1e5+1;
const int seg_n = 2*(1e5+1);
int seg[mxN<<2];
pair<int, int> idx_hash[mxN];

int range(int l, int r, int L, int R, int root);
void update(int idx, int L, int R, int root);

int main(){
    int n;
    cin>>n;
    int tmp;
    int N = 2*n;
    //initialize
    for(int i = 0; i<mxN; ++i){
        idx_hash[i].first = -1;
    }
    for(int i = 0; i<seg_n; ++i){
        seg[i] = 0;
    }
    //fill hash
    for(int i = 0; i<N; ++i){
        cin>>tmp;
        if(idx_hash[tmp].first==-1){
            idx_hash[tmp].first = i;
        }
        else{
            idx_hash[tmp].second = i;
        }
    }
    ll ans = 0;
    for(int i = 1; i<=n; ++i){
        int l = idx_hash[i].first;
        int r = idx_hash[i].second;
        //cout<< l<<" "<<r<<" "<<endl;
        ans+=range(l, r, 0, seg_n-1, 1);
        update(l, 0, seg_n-1, 1);
        update(r, 0, seg_n-1, 1);
    }
    cout<< ans<<endl;
}
int range(int l, int r, int L, int R, int root){
    if(l==L&&r==R){
        return seg[root];
    }
    int mid = (L+R)/2;
    if(r<=mid){
        return range(l, r, L, mid, 2*root); //都在左子
    }
    else if(l>mid){
        return range(l, r, mid+1, R, 2*root+1); //都在右子
    }
    //跨於左右子
    return range(l, mid, L, mid, 2*root)+range(mid+1, r, mid+1, R, 2*root+1);
}
void update(int idx, int L, int R, int root){
    if(L==R){
        seg[root] = 1;
        return;
    }
    int mid = (L+R)/2;
    if(idx<=mid){
        update(idx, L, mid, 2*root);
    }
    else{
        update(idx, mid+1, R, 2*root+1);
    }
    seg[root] = seg[2*root]+seg[2*root+1];
}
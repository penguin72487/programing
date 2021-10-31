#include <iostream>
#include<algorithm>
#include<fstream>
#define ll long long
using namespace std;


int range(int l, int r, int L, int R, int root,int seg[]);
void update(int idx, int L, int R, int root,int seg[]);

int main(){
    int n;
    fstream file;
    //file.open("f315.txt");
    file.open("f315p409_10.txt");
    file>>n;
    int tmp;
    int N = n<<1;
    int seg[(N<<2)+1];
    pair<int, int> idx_hash[n+3];
    //initialize
    for(int i = 0; i<n; ++i){
        idx_hash[i].first = -1;
    }
    fill(seg,seg+N*4+1,0);
    //fill hash
    for(int i = 0; i<N; ++i){
        file>>tmp;
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
        ans+=range(l, r, 0, N, 1,seg);
        update(l, 0, N, 1,seg);
        update(r, 0, N, 1,seg);
    }
    cout<< ans<<endl;
}
int range(int l, int r, int L, int R, int root,int seg[]){
    if(l==L&&r==R){
        return seg[root];
    }
    int mid = (L+R)/2;
    if(r<=mid){
        return range(l, r, L, mid, 2*root,seg); //都在左子
    }
    else if(l>mid){
        return range(l, r, mid+1, R, 2*root+1,seg); //都在右子
    }
    //跨於左右子
    return range(l, mid, L, mid, 2*root,seg)+range(mid+1, r, mid+1, R, 2*root+1,seg);
}
void update(int idx, int L, int R, int root,int seg[]){
    if(L==R){
        seg[root] = 1;
        return;
    }
    int mid = (L+R)/2;
    if(idx<=mid){
        update(idx, L, mid, 2*root,seg);
    }
    else{
        update(idx, mid+1, R, 2*root+1,seg);
    }
    seg[root] = seg[2*root]+seg[2*root+1];
}
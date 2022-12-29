#include<bits/stdc++.h>
using namespace std;
class lion{
public:
    int h;
    int w;
    lion(){

    }
    lion(int h,int w) : h(h), w(w) {}
    bool operator<(lion a) {
        return (h*w<a.h * a.w );
    }



};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    lion lis[n];//liom
    for(int i=0;i<n;++i){
        cin >> lis[i].h;
    }
    for(int i=0;i<n;++i){
        cin >> lis[i].w;
    }
    // sort(lis, lis + n, [](auto &a, auto &b)->bool
    //      { return (a.h * a.w < b.h * b.w); });
    sort(lis, lis + n);
    cout << lis[0].h << " " << lis[0].w << "\n";

    return 0;
}
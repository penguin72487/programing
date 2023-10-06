#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    char k;
    int op_H, op_M;
    int ed_H, ed_M;
    cin>>op_H>>k>>op_M;
    cin>>ed_H>>k>>ed_M;
    int m = (op_M + ed_M)+op_H*60+ed_H*60;
    m/=2;
    cout << setw(2) << setfill('0')<<m/60<<":"<<setw(2) << setfill('0')<<m%60<<"\n";
    return 0;
}
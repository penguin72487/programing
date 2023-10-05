#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n, s;
    cin>>n>>s;
    long long sum = 0;
    for(int i=0,a; i<n; ++i)
    {
        cin >> a;
        if(a>=s){
            ++sum;
        }
    }
    cout << (sum==0?-1:sum) << "\n";
    return 0;
}
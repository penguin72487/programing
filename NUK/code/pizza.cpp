#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n;
    cin >> n;
    ++n;
    if(n == 1){
        cout <<"0\n";
    }
    else if(n&1){
        cout << n<<"\n";
    }
    else {
        cout<<n/2<<"\n";
    }
    return 0;
}
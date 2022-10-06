#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    int n=0;
    while(t--){
        ++n;
        int a, b;
        cin >> a >> b;
        a |= 1;
        int sum=0;
        for (int i = a,tmp=b+1; i < tmp;i+=2)
        {
            sum += i;
        }
        cout<<"Case " <<n<<": " << sum << "\n";
    }
    return 0;
}
#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
    a^=b^=a^=b;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(b>a)
        {
            swap(a, b);
        }
        if(a%3==0&&b%3==0)
        {
            cout << "YES\n";
        }
        else if((a%3==2&&b%3==1)||(a%3==1&&b%3==2)){
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}
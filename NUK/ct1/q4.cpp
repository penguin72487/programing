#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a, b;
    while(cin>>a>>b)
    {
        int ans = 0;
        int add = 0;
        if(a==b&&a==0)
        {
            break;
        }
        while(a&&b)
        {
            if(a%10+b%10+add>9)
            {
                add = 1;
                ++ans;
            }
            else {
                add = 0;
            }
            a /= 10;
            b /= 10;
        }
        if(ans==0)
        {
            cout << "No carry operation.\n";
        }
        else {
            cout << ans << " carry operation.\n";
        }
        
    }
    return 0;
}
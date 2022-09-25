#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans_A, ans_B;
        if(a>=c)
        {
            ans_A = -1;
        }
        else 
        {
            if(a==(c/b))
            {
                ans_A = c / a+a-1;
            }
            else
            {
                ans_A = c / a;
            }
            
        }

        if(a<=(c/b))
        {
            ans_B = -1;
        }
        else
        {
            ans_B = b;
        }
        cout<<ans_A<<" "<<ans_B<<"\n";
    }
    return 0;
}
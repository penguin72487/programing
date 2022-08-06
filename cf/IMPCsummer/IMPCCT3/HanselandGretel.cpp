#include <iostream>
#include <algorithm>
using namespace std;
void swap(int &a,int &b)
{
    a^=b^=a^=b;
}
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int b[n];
        int max_A=0;
        int max_B=0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            max_A = max(a[i], max_A);
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(a[i] < b[i])
            {
                swap(a[i],b[i]);
                max_A = max(a[i], max_A);
            }
            max_B = max(b[i], max_B);
        }
        cout << max_A * max_B << "\n";
    }

return 0;
}
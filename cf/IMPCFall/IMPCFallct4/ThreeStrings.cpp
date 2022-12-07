#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        int n=a.size();
        bool flag = 1;
        for(int i=0; i<n; i++){
            if (a[i]==c[i] || b[i]==c[i])
            {

            }
            else {
                //cout << "NO\n";
                flag = 0;
                break;
            }
        }
        if(flag ==1)
        {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
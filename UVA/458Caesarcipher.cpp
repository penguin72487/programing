#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    int k = '*' - '1';
    while(cin>>s){
        for(auto& it:s)
        {
            cout << char(it + k);
        }
        cout << "\n";
    }
    return 0;
}
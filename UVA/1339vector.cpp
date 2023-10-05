#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s,t;
    while(cin>>s>>t)
    {
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(auto& it:s){
            ++a[it - 'A'];
        }
        for(auto& it:t){
            ++b[it - 'A'];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        cout << (a == b ? "YES\n" : "NO\n");
    } 
    return 0;
}
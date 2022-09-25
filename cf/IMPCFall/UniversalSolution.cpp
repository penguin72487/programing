#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    unordered_map<char,char> cc_Win;// r 0 p 1 s 2
    cc_Win['R'] = 'P';
    cc_Win['P'] = 'S';
    cc_Win['S'] = 'R';
    string s;
    while(t--){
        cin >> s;
        for(auto it=s.begin();it!=s.end();++it)
        {
            cout << cc_Win[*it];
        }
        cout << "\n";
    }
    return 0;
}
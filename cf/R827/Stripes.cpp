#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    //int n=8, m=8;

    string s[8];
    while(t--){
        char ans = '.';
        for(int i=0; i<8; i++){
            cin >> s[i];
            if(s[i]=="RRRRRRRR")
            {
                ans = 'R';
            }
        }
        if(ans=='.')
        {
            ans = 'B';
        }
        cout << ans << "\n";
    }

    return 0;
}
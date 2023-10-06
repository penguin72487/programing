#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    bool flag = 1;
    while(getline(cin, s))
    {
        // if(s=="0")
        // {
        //     break;
        // }
        
        for(auto& it:s){
            if(it=='"'&&flag)
            {
                cout << "``";
                flag = 0;
            }
            else if(it=='"'&&(!flag))
            {
                cout << "''";
                flag = 1;
            }
            else{
                cout << it;
            }

        }
        cout << "\n";
    }
    return 0;
}
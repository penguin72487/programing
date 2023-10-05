#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long sum = 0;
    cin >> sum;
    cin.get();
    //cin.close();
    string s;
    
    getline(cin, s);
    stringstream ss(s);
    char opt;
    while(ss>>opt) 
    {
        
       
        long long tmp;
        ss >>tmp;
        switch(opt)
        {
            case '+':
                sum += tmp;
                break;
            case '-':
                sum -= tmp;
                break;
            case '*':
                sum *= tmp;
                break;
            case '/':
                sum /= tmp;
                break;
        }
    }
    cout << sum << "\n";

    return 0;
}
/*
1
+3 *-3
*/

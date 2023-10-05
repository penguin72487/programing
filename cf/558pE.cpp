#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int a, b,c;
    for (int i = 0; i < t;++i)
    {
        cin >> a >> b>>c;
        if(c==0)
        { 
            sort(s.begin() + a - 1, s.begin() + b, [](char a, char b) -> bool
             { return (a > b); });
        }
        else {
            sort(s.begin() + a - 1, s.begin() + b);
        }
        
    }
    cout << s << "\n";

    return 0;
}
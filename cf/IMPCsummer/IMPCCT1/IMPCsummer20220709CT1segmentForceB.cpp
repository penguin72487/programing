#include<iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            cout << "-1\n";
            continue;
        }
        string s="2";
        for(int i=1; i<n; ++i){
            s += "9";
        }
        cout << s << "\n";
    }
    
}
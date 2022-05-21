#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int s;
        cin >> t >> s;
        int ans=0;
        for(int i=0; i<n;++i)
        {
            int tmp;
            cin >> tmp;
            ans += tmp;
        }
        if(ans==s)
        {
            cout << "YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
#include <iostream>
using namespace std;
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    while(getline(cin, s))
    {
        for(auto it=s.begin(); it != s.end(); ++it)
        {
            cout << (char)(*it-7);
        }
        cout<<"\n";
    }
    return 0;
}

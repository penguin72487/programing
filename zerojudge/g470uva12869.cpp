#include <iostream>
using namespace std;
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    long long a, b;
    while(cin>>a>>b)
    {
        if(a==b&&a==0)
        {
            break;
        }
        cout << b/5 -a/5+1 << "\n";
    }
    return 0;
}

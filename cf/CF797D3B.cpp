#include <iostream>
#include <numeric>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        
        if(a[0]<b[0])
        {
            cout << "NO\n";
            continue;
        }
        else if(n==1)
        {
            cout << "YES\n";
            continue;
        } 
        int adjacent_a[n];
        adjacent_difference(a,a+n,adjacent_a);
        int adjacent_b[n];
        adjacent_difference(b, b + n, adjacent_b);
        bool flag = 1;

        for(int i = 1; i < n; i++)
        {
            if(adjacent_a[i] != adjacent_b[i])
            {
                if(b[i]!=0)
                {
                    flag = 0;
                    cout << "NO\n";
                    break;
                }
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
    }
}
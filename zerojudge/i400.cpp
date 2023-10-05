#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    string bit[m];
    for(int i = 0; i < m;++i)
    {
        int i_Sum = 0;
        cin>>bit[i];
        for(int j = 0; j < n;++j)
        {
            if(bit[i][j] =='1')
            {
                ++i_Sum;
            }
        }
        bit[i][n] = i_Sum;
    }
    string s,t;
    cin >> t;
    for(int i = m-1; i>-1;--i)
    {
        
        s = "";
        if (bit[i][n] & 1)
        {
            for (int j = n - 1; j > -1; j--)
            {
                if (bit[i][j] & 1)
                {
                    s += t[j];
                }
                else
                {
                    s = t[j] + s;
                }
            }
            t = s;
            if(n&1)
            {
                s = t.substr(n / 2 + 1);
                s += t[n / 2];
                s += t.substr(0, n / 2 );
            }
            else
            {
                s = t.substr(n / 2);
                s += t.substr(0, n / 2);
            }
            t = s;
        }
        else
        {
                for (int j = n - 1; j > -1; j--)
                {
                    if (bit[i][j] & 1)
                    {
                        s += t[j];
                    }
                    else
                    {
                        s = t[j] + s;
                    }
                }
                t = s;
        }
    }
    cout<<s<<"\n";
}
#include<iostream>
#include<algorithm>
#include<string>
#include <sstream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    ++n;
    string ans, s;
    getline(cin,ans);
    int i_len[n][n];
    while (getline(cin,s))
    {
        stringstream ss(s);
        s.clear();
        char tmp;
        while(ss>>tmp)
        {
            s += tmp;
        }
        for (int i = 0; i < n; ++i)
        {
            i_len[i][0] = 0;
            i_len[0][i] = 0;
            }
        for (int i = 1; i < n;++i)
        {
            for (int j = 1; j < n;++j)
            {
                if(ans[i]==s[j])
                {
                    i_len[i][j] = i_len[i - 1][j - 1] + 1;
                }
                else
                {
                    i_len[i][j] = max(i_len[i - 1][j], i_len[i][j - 1]);
                }
            }
        }
        cout << i_len[n - 1][n - 1];
    }
}
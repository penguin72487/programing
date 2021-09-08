#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    n += 2;
    m += 2;
    int matrix[n][m];
    fill(*matrix, matrix[n - 1] + m, -101);

    
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << matrix[i][j]<<" ";
        }
        cout << "\n";
    }
    int main_DP[n][m];

    fill(*main_DP, main_DP[n - 1] + m, -101);

    for (int i = 1; i < n-1;++i)
    {
        for (int j = 1; j < m-1;++j)
        {
            cin >> matrix[i][j];
            if(i==1)
            {
                main_DP[i][j] = matrix[i][j];
            }
            
        }
    }
    for (int i = 1; i < n-1;++i)
    {
        for (int j = 1; j < m-1;++j)
        {
            cout << main_DP[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n;++i)
    {
        int r_Dp[m];
        fill(r_Dp, r_Dp + m,-101);
        int l_Dp[m];
        fill(l_Dp, l_Dp + m,-101);
        for (int j = 0; j < m;++j)
        {
           l_Dp[j] = max(l_Dp[j],matrix[i][j-1]+matrix[i][j]);
        }
        for (int j = m-1; j >0;--j)
        {
            
            r_Dp[j] = max(r_Dp[j],matrix[i][j+1]+matrix[i][j]);
        }
        for (int j = 0; j < m;++j)
        {
            main_DP[i][j] = max(r_Dp[j], l_Dp[j]);
        }
    }


        /*
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << matrix[i][j].i_Data<<" ";
        }
        cout << "\n";
    }
    */
    for (int i = 1; i < n-1;++i)
    {
        for (int j = 1; j < m-1;++j)
        {
            cout <<"dp"<< main_DP[i][j] << " ";
        }
    }
        
}
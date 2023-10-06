#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int score[n][n];
    for(int j = 0; j < n; j++)
    {
        cin>>score[0][j];
    }
    const int MOD = n;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            score[i][j] = max(score[i-1][j]+score[i-1][(j-2+MOD)%MOD],score[i-1][j]+score[i-1][(j+2+MOD)%MOD]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<score[i][j]<<" ";
        }
        cout << "\n";
    }
}
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int coins[]={1,3,5,7};
    int x;
    while(cin>>x)
    {
        int dp[x+1];
        for (int i=0; i<=x; i++)
        {
            dp[i]=i;
        }
        for (int i=0; i<4; i++)
        {
            for (int j=coins[i]; j<=x; j++)
            {
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        cout<<dp[x]<<endl;

    }

}

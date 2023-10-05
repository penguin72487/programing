#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    
    int c,n;
    while(cin>>c>>n)
    {
    	int coins[n];
    	for(int i=0;i<n;i++)
    	{
    		cin>>coins[i];
		}
		sort(coins,coins+n);
        int dp[c+1]={0,1};
        for (int i=1; i<=c; i++)
        {
            dp[i]=i;
        }

        for (int i=0; i<n; i++)
        {
            for (int j=coins[i]; j<=c; j++)
            {
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        cout<<dp[c]<<endl;

    }

}


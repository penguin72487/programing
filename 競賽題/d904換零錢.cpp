#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int c;
	int n;
	cin>>c>>n;
	int corn[n];
	for(int i=0;i<n;i++)
	{
		cin>>corn[i];
	}
	sort(corn,corn+n);
	for(int i = 0; i < n; i++)
	{
		for(int j = coins[i]; j <= c; j++)
		{
			memo[j] = min(memo[j], memo[j - coins[i]] + 1);
		}
	} 
		//every coin
		
}


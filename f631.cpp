#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int $[n],cost[m];
	int $t=0,costt=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>$[i];
		$t+=$[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>cost[i];
		costt+=cost[i];
	}
	if($t<costt)
	{
		cout<<"Oh My God"<<endl;
	}
	else
	{
		
		for(i=0;i<n;i++)
		{
			$[i]-=cost[i];
		}
		for(i=0;i<n;i++)
		{
			if($[i]<0)
			{
				$[i+1]-=$[i];
				$[i]=0;
			}
		}
	}
}

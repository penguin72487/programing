#include<iostream>
using namespace std;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int a[10][10]={1,2,3,4,5,6,7,8,9,10
				  ,2,2,3,4,5,6,7,8,9,10
				  ,3,3,3,4,5,6,7,8,9,10
				  ,4,4,4,4,5,6,7,8,9,10
				  ,5,5,5,5,5,6,7,8,9,10
				  ,6,6,6,6,6,6,7,8,9,10
				  ,7,7,7,7,7,7,7,8,9,10
				  ,8,8,8,8,8,8,8,8,9,10
				  ,9,9,9,9,9,9,9,9,9,10
				  ,10,10,10,10,10,10,10,10,10,10
	
	};
	int n,t;
	cin>>n>>t;
	
	for(int i=0;i<t;i++)
	{
		int ans=0;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int i=y1-1;i<y2;i++)
		{
			for(int j=x1-1;j<x2;j++)
			{
				ans+=a[i][j];
			}
		}
		cout<<ans<<"\n";
	}
}


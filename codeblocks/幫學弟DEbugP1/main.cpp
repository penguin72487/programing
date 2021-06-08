#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
    int ans[10][10];
    int f[10][10];
	int r,c,sum,count;
	cout<<"hi\n";
	while(cin>>r>>c)
	{

		memset(f,0,sizeof(f));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cin>>f[i][j];
				ans[i][j]=f[i][j];
			}
		}

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if(f[i][j]==0)
				{
					sum=count=0;
					for(int k=0;k<4;k++)
					{
						if(f[i+dy[k]][j+dx[k]]!=0)
						{
							count++;
							sum+=f[i+dy[k]][j+dx[k]];
						}
					}
					ans[i][j]=sum/count;
				}
			}
		}

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}

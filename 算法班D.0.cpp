#include<iostream>
using namespace std;
int main()
{
	int r,c,r2,c2;
	cin>>r>>c;
	int val[r][c]={0};
	int i,j,k;
	long long int temp;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>temp;
			val[i][j]=temp%100000007;
		}
	}
	cin>>r2>>c2;
	int val2[r2][c2]={0};
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			cin>>temp;
			val2[i][j]=temp%100000007;
		}
	}
	if(c==r2)
	{
		long long int ans[r][c]={0};
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				ans[i][j]=0;
				for(k=0;k<c;k++)
				{
					ans[i][j]+=val[i][k]*val2[k][j];
				
				}
			
			}
		}
		
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				
				if(ans[i][j]<0)
				cout<<ans[i][j]%100000007+100000007<<" ";
				else
				cout<<ans[i][j]%100000007<<" ";
			}
			cout<<endl;
		}	
		
		
		
		
		
		
	}
	else if(c2==r)
	cout<<"incommutable!"<<endl;
	else
	cout<<"unmultipliable!"<<endl;

} 

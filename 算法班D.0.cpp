#include<iostream>
using namespace std;
int main()
{
	int r,c,r2,c2;
	cin>>r>>c;
	long long int val[r][c]={0};
	int mod =100000007;
	int i,j,k;
	long long int temp;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>temp;
			val[i][j]=(temp%mod+mod)%mod;
		}
	}
	cin>>r2>>c2;
	long long int val2[r2][c2]={0};
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			cin>>temp;
			val2[i][j]=(temp%mod+mod)%mod;
		}
	}
	if(c==r2)
	{
		long long int ans[r][c]={0};
		for(i=0;i<r;i++)
		{
			for(j=0;j<c2;j++)
			{
				ans[i][j]=0;
				for(k=0;k<c;k++)
				{
					ans[i][j]+=(val[i][k]*val2[k][j])%mod;
				
				}
			
			}
		}
		
		for(i=0;i<r;i++)
		{
			for(j=0;j<c2;j++)
			{
				cout<<(mod+ans[i][j])%mod <<" ";
			}
			cout<<endl;
		}	
	}
	else if(c2==r)
	cout<<"incommutable!"<<endl;
	else
	cout<<"unmultipliable!"<<endl;

} 

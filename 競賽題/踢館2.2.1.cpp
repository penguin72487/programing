#include<iostream>
#include<algorithm> 
using namespace std;
bool f(int k);
int main()
{
	int n;
	cin>>n;
	int r=n+1,c=n+1;
	unsigned short l[r][c]={0},i,j;
	for(i=1;i<r;i++)
	{
		cin>>l[0][i];
	}
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			l[i][j]=l[i-1][j]; 
			if(l[i][j]==l[0][i]&&l[i][j]<l[i][j-1])
			{
				find(l[i][1],l[i][j],f);
				l[i][j]^=l[i][j-1]^=l[i][j]^=l[i][j-1];	
			
		}
		}
	}
		for(i=1;i<r;i++)
	{ 
		for(j=1;j<c;j++)
		cout<<l[i][j]<<" ";
		cout<<endl; 
	}
	int int_r,int_c,int_n;
	cin>>int_n;
	for(i=0;i<int_n;i++)
	{
		cin>>int_r>>int_c;
		cout<<l[int_r][int_c]<<endl;
	}
	
}
bool f(int k)
{
	int i=i,j=j;
	int o=l[i][j];
	return k>o;
}

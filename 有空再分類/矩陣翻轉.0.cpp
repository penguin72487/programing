#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int r,c,m;
	while (cin>>r>>c>>m)
	{
	char l[max(r,c)][max(r,c)];
	int i,j,k;
	int a[m];
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			cin>>l[i][j];
		}
	}
	cout<<r<<" "<<c<<endl;
		for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(k=m;k>=0;k--)
	{
		if(a[k]==0)
		{
			for(i=0;i<r;i++)
			{
			for (j=0;j<c;j++)
			{
			l[i][c-1-j]^=l[i][j]^=l[i][c-1-j]^=l[i][j];
			}
			}
			r^=c^=r^=c;	
		}
		else if(a[k]==1)
		{
			for(i=0;i<r;i++)
			{
			for (j=0;j<c;j++)
			{
			l[r-1-i][j]^=l[i][j]^=l[r-1-i][j]^=l[i][j];
			}
			}
		}
	}
	cout<<r<<" "<<c<<endl;
		for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	
 } 
 } 

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int r,c,m;
	cin>>r>>c>>m;
	int l[max(r,c)][max(r,c)];
	int i,j,k;
	int a[m];
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;i++)
		{
			cin>>l[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(k=m;k>0;k--)
	{
		if(a[k]==1)
		{
			for(i=0;i<r/2;i++)
			{
				for(j=0;j<c;j++)
				l[0+i][j]^=l[r-1-i][j]^=l[0+i][j]^=l[r-1-i][j];
			}
			
		}
		else
		{
				for(i=0;i<r/2;i++)
			{
				for(j=0;j<c;j++)
				{
					
				}
			}
			r^=c^=r^=c;
		}
		
		
	}
	
 } 

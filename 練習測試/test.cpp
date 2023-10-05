#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,r,c;
	cin>>n;
	r=n+1;
	c=n+1;
	int l[n][n]={0};
	int i,j;
	for(i=0;i<n;i++)
	cin>>l[0][i];
	for(i=0;i<r;i++)	
	{
		for(j=0;j<c;j++)
		{
			find(l[0][1],l[0][c],)
		}
	}
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>r>>c;
		cout<<l[r][c]<<endl;
	}
	
}

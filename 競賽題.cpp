#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int i,j,n;
	while (cin>>n)
	{
	int x[n],y[n],h[n],d[n];
	for (i=0;i<n;i++)
	{
	cin>>x[i]>>y[i]>>h[i];
	d[i]=x[i]*x[i]+y[i]*y[i] ;
}
	 sort(d, d+n);
	for(i=0;i<n;i++)
	{
	
		
		for(j=0;j<n;j++)
		{	
				if(x[j]==0&&y[j]==0)
		{
			x[0]^=x[j]^=x[0]^=x[j]; 
			y[0]^=y[j]^=y[0]^=y[j];	
		}
			if(d[i]==x[j]*x[j]+y[j]*y[j])
			{
				x[i]^=x[j]^=x[i]^=x[j]; 
				y[i]^=y[j]^=y[i]^=y[j];	
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d %d\n",x[i],y[i]);
	

}
	
 } 

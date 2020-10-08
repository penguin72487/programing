#include<iostream>
#include<algorithm>
#include<vector>
#include<set>  
using namespace std;
int main()
{
	int i,j,n,happy=0;
	while (cin>>n)
	{
	int x[n],y[n],h[n]={0},d[n],d2[n];
	for (i=0;i<n;i++)
	{
	cin>>x[i]>>y[i]>>h[i];
	d[i]=x[i]*x[i]+y[i]*y[i] ;
	d2[i]=d[i];
	
}
	 sort(d, d+n);
	for(i=0;i<n;i++)
	printf("%d\n",d[i]);
	for(i=0;i<n;i++)
	{	
		for(j=i+1;j<n-1;j++)
		{	
			if(d[i]==d2[j])	
				h[i]^=h[j]^=h[i]^=h[j];
			
		}
	}
	while(h[i]>=0)
	{
		int int_max=0,int_min=1000000000;
		for(i=0;i<n;i++)
		{
		int_max=max(h[i],int_max);
		for(j=i;j<n;j++)	
		int_min=min(h[j],int_min);
	}
		
		happy+=int_max-int_min;
		for(int k=i;k<j;k++)
		h[k]=-1;
		cout<<happy<<endl;
	}
  

}
	
 } 

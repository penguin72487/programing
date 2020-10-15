#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
	int i,j;
	int x[n],y[n],h[n]={0},d[n],d2[n];
	for (i=0;i<n;i++)
	{
	cin>>x[i]>>y[i]>>h[i];
	d[i]=x[i]*x[i]+y[i]*y[i] ;
	d2[i]=d[i];
	
}
	 sort(d, d+n);
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n-1;j++)
		{	
			if(d[i]==d2[j])	
				h[i]^=h[j]^=h[i]^=h[j];
			
		}
	}
	int int_max=0;		
		for(i=0;i<n;i++)
		{  
		for(j=i;j<n;j++)
			int_max=max(int_max,h[i]-h[j]);
}
		 
		cout<<int_max<<endl; 
  

}
	
 } 

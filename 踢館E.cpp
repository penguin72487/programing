#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long int a[1000],i=0,n,b[1000],k,x=0,y=0;
	for(cin>>n;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i]; 
	}
	cin>>k;
	for(i=0;i<n;i++)
	{
		for (int j =i+1;j<n;j++)
		{
			if(a[i]*b[j]<=k||a[i]*b[j]>0||max(a[i],b[j])>min(a[i],b[j]))
			{
				if(a[i]*b[j]>=x)
				{
					y=x;
					x=a[i]*b[j];
				}
				else if(a[i]*b[j]<x||a[i]*b[j]>=y)
				{
					y=a[i]*b[j];
				}
			}
		}
	}
	if (y==0)
	cout<<0<<endl;
	else
	cout<<x<<endl;
 } 

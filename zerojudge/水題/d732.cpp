#include<iostream>
using namespace std;
int n;
int twofind(int p[],int a)
{
	int mid,high=n-1,low=0;
	while(high>=low)
	{
		mid=(high+low)/2;
		if(a<p[mid])
		{
			high=mid-1;	
		} 
		else if(a>p[mid])
		{
			low=mid+1;
		}
		else
		return mid+1;
	}
	return 0;	
}
int main ()
{
	int m;
	cin>>n>>m;
	int p[n];
	for(int i=0;i<n;i++)
	cin>>p[i];
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		cout<<twofind(p,a)<<endl;
	}
	
}

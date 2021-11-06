#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,int_max=-1000000,score;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	cin>>score;
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		   if(a[i]*a[j]<=score)
		   int_max=max(int_max,a[i]*a[j]);
	} 	    
	}
	cout<<int_max<<endl;
}

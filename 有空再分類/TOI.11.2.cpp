#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int c[n];
	int i,j;
	for(i=0;i<n;i++)
		cin>>c[i];
	int gost;
	int t;
	
	cin>>gost;
	cin>>t;
	int num;
	for(i=0;i<t;i++)
	{
		cin>>num;
		int j=0;
		while(c[j]!=num)
		j++;
		gost^=c[j]^=gost^=c[j];
		
	}
	for(i=0;i<n;i++)
	cout<<c[i]<<" ";
	cout<<endl;
	
}

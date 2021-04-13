#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,d,e,f,n;
	cin>>a>>b>>c>>d>>e>>f;
	cin>>n;
	int int_max=-10000000,int_min=10000000;
	for(int i=0;i<=n;i++)
	{
		int_max=max(a*i*i+b*i+c+d*(n-i)*(n-i)+e*(n-i)+f,int_max);
	 } 
	cout<<int_max<<endl;
	
	
	
	
	
	
	 
 } 

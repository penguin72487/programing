#include<iostream>
using namespace std;
int main()
{
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a>b)
	{
		cout<<x+(a-1-b)*y<<endl;	
	}
	else
	{
		cout<<x+(b-a)*y<<endl;
	}
}

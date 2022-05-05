#include<iostream>
using namespace std;
long double f(long double p,int count);
int main()
{

cout<<f(1,100)<<endl;
}
long double f(long double p,int count)
{
	
	if(count==0)
	{
		return 0;
	}
	else if(count<=50)
	{
		long double tmp=(0.02*(51-count));
		cout<<p<<" "<<tmp<<" "<<count<<"\n";
		return f(p*(1-0.02*(51-count)),count-1)+p*tmp; 
	}
	else 
	{
		cout<<p<<" "<<0.02<<" "<<count<<"\n";
		return f(p*0.98,count-1)+p*0.02;
	}
}

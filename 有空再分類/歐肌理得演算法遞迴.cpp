#include<iostream>
using namespace std;
int o_al(int a,int b)
{
	if(a%b==0)
	return b;
	else
	return o_al(b,a%b);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<o_al(a,b)<<endl; 
}

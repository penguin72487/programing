#include<iostream>
using namespace std;
unsigned long long l[1000];
unsigned long long f(int n)
{

	if(n<0)
	return 0;
	if(n==1)
	return 1;
	if(l[n])
	return l[n];
	return l[n]=f(n-1)+f(n-2) ;
}
int main()
{
	int n;

	while (cin>>n&&n!=-1)
	{

	cout<<f(n)<<endl;
	}
} 

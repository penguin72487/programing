#include<iostream>
using namespace std;
unsigned long l[10000];
unsigned long f(int n)
{

	if(n==0||n==1)
	return 1;
	if(l[n]!=0)
	return l[n];
	return l[n]=f(n-1)*n ;
}
unsigned long p(int n,int m)
{
	return f(n)/f(m);
}
unsigned long c(int n,int m)
{
	return p(n,m)/f(n);
}

int main()
{

int n;
while (cin>>n&&n!=-1)
{

cout<<f(n)<<endl;
cout<<p(9,7)<<endl;
cout<<c(5,3)<<endl;
cout<<c(5,2)<<endl;
}
}

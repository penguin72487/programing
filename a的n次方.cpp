#include<iostream>
using namespace std;
unsigned long l[10000][10000];
unsigned long f(int a,int n)
{

	if(n==0)
	return 1;
	if(n==1)
	return a;
	if(l[a][n]!=0)
	return l[a][n];
	return l[a][n]=f(a,n-1)*a ;
}
int main()
{
	int a,n;

while (cin>>a>>n)
{

cout<<f(a,n)<<endl;
}
} 

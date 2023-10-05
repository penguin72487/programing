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

int main()
{

int n;
while (cin>>n&&n!=-1)
{

cout<<f(n)<<endl;

}
}

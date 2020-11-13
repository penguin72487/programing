#include<iostream>
using namespace std;
unsigned long  l[10001];
unsigned long f(int n)
{

	if(n==0||n==1)
	return 1;
	if(l[n]!=0)
	return l[n];
	return l[n]=(f(n-1)+f(n-2))% 1000000007;
}
int main()
{
	int n;

while (cin>>n)
{
		for(int i=0;i<n;i++)
		l[i]==0;
		cout<<f(n)<<endl;
}
} 

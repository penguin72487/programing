#include<iostream>
using namespace std;
	int l[100];
int f(int n)
{

	if(n==0||n==1)
	return 1;
	if(l[n]!=0)
	return l[n];
	return l[n]=f(n-1)+f(n-2) ;
}
int main()
{
	int n;

while (cin>>n)
{
		for(int i=0;i<n;i++)
		l[i]==0;
cout<<n<<"!= "<<f(n)<<endl;
}
} 

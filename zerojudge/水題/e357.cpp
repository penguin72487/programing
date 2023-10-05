#include<iostream>
using namespace std;
int l[10000000];
int f(int n)
{

	if(n==1)
	return 1;
	if(l[n]!=0)
	return l[n];
	if(n%2==0)
	return l[n]=f(n/2);
	return l[n]=f(n-1)+f(n+1) ;
}
 int main()
{
	int n;
cin>>n;
cout<<f(n)<<endl;

} 

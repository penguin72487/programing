#include<iostream>
#include<cmath>
using namespace std;
long long int a[2];
long long int n,p,q,r; 
long long int f(long long int n);
int main()
{
	
	cin>>p>>q>>r>>a[0]>>a[1]>>n;
	long long int ans=f(n)%10000;
	for(int i=0;i<3-log10(ans);i++) 
	cout<<"0";
	cout<<ans<<endl;

	return 0;
}
long long int f(long long int n)
{
	if(n<2)
	{
		return a[n];
	}
	return ((p*(f(n-1)))%10000+(q*(f(n-2)))%10000+r)%10000;
}

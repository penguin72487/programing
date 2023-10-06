#include<iostream>
using namespace std;
long long pow(int a,int n);
int main()
{
	int a,n;
	while(cin>>a>>n)
	{
		cout<<pow(a,n)<<endl;
	}
	
}
long long pow(int a,int n)
{
  int r=1;
  while(n)
  {
    if(n&1)
	r*=a;
    a*=a;
    n>>=1;
  }
  return r;
}

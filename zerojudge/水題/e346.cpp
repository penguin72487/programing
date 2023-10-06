#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,t;
	cin>>n;
	long long p[n];
	for(auto it=p;it!=p+n;it++)
	{
		cin>>*it;
	}
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b,num=0;
		cin>>a>>b;
		for(auto it=p+a-1;it!=p+b;it++)
		num+=*it;
		cout<<num<<endl;
	}
	
	
	
}

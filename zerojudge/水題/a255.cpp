#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		for(auto it=a;it!=a+n;it++)
		cout<<*it<<" ";
		cout<<endl;
	}
}

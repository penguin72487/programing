#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	set<int> a;
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		a.insert(b);
	}
	for(int i=0;i<q;i++)
	{
		int b;
		cin>>b;
		if(a.find(b)!=a.end())
		{
			cout<<"Yes"<<endl; 
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}

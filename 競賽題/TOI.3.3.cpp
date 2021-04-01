#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int n_h=0;
	int m_h=0; 
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		n_h+=tmp;
	} 
	for(int i=0;i<m;i++)
	{
		int tmp;
		cin>>tmp;
		m_h+=tmp;
	} 
	if(n>m&&n_h>m_h)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
}

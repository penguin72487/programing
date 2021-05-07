#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	list<int> a;
	int tmp,tmp2;
	while(n--)
	{
		
		cin>>tmp>>tmp2;
		
		unsigned long long tol=0;
		a.erase(a.begin(),lower_bound(a.begin(),a.end(),tmp2));
		
		a.insert(upper_bound(a.begin(),a.end(),tmp),tmp);
		for(auto it=a.begin();it!=a.end();it++)
		{
			tol+=*it;
		}
		cout<<tol<<"\n";
	}
	
}

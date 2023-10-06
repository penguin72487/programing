#include<iostream>
#include<deque>
using namespace std;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	priority_queue<int> a;
	int tmp,tmp2;
	while(n--)
	{
		
		cin>>tmp>>tmp2;
		
		unsigned long long tol=0;
		
		for(auto it=a.begin();it!=a.end();it++)
		{
			tol+=*it;
		}
		cout<<tol<<"\n";
	}
	
}

#include<iostream>
#include<list>
using namespace std;


bool even(int x)
{

if(x<1)
return true;

else
return false;

}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	list<int> a;
	int tmp,tmp2;
	for(int i=0;i<n;i++)
	{
		
		cin>>tmp>>tmp2;
		
		unsigned long long tol=0;
		for(auto it=a.begin();it!=a.end();it++)
		{
			*it-=tmp2;
		}
		a.remove_if(even);

		a.push_back(tmp);
		for(auto it=a.begin();it!=a.end();it++)
		{
			tol+=*it;
		}
		cout<<tol<<"\n";
	}
	
}


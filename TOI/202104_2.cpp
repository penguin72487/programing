#include<iostream>
#include<list>
using namespace std;

int tmp,tmp2;
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
	for(int i=0;i<n;i++)
	{
		
		cin>>tmp>>tmp2;
		a.push_back(tmp);
		int tol=tmp;
		for(auto it=a.begin();it!=(--a.end());it++)
		{
			*it-=tmp2;
		}
		a.remove_if(even);
		/*
		cout<<"list\n";
		for(auto it=a.begin();it!=(a.end());it++)
		{
			cout<<*it<<" ";
		}
		cout<<"\n";
		*/
		for(auto it=a.begin();it!=(--a.end());it++)
		{
			tol+=*it;
		}
		cout<<tol<<"\n";
	}
	
}


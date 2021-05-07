#include<iostream>
#include<list>
#include<algorithm>
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
<<<<<<< .mine
	int tmp,tmp2;
	while(n--)
=======
	int tmp,tmp2;
	for(int i=0;i<n;i++)
>>>>>>> .theirs
	{
		
		cin>>tmp>>tmp2;
<<<<<<< .mine
		
		unsigned long long tol=0;
		a.erase(a.begin(),lower_bound(a.begin(),a.end(),tmp2));
		
		a.insert(upper_bound(a.begin(),a.end(),tmp),tmp);
		for(auto it=a.begin();it!=a.end();it++)
=======
		
		unsigned long long tol=0;
		for(auto it=a.begin();it!=a.end();it++)



>>>>>>> .theirs
		{
<<<<<<< .mine







=======
			*it-=tmp2;
		}
		a.remove_if(even);

		a.push_back(tmp);
		for(auto it=a.begin();it!=a.end();it++)
		{
>>>>>>> .theirs
			tol+=*it;
		}
		cout<<tol<<"\n";
	}
	
}

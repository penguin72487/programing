#include<iostream>
#include<set>
using namespace std;
int main()
{
	int l;
	cin>>l;
	int n;
	while(cin>>n)
	{
		int ans=0;
		set<int> c={0,l};
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			c.insert(a);
			auto it = c.insert(a).first;
   			ans += *next(it) - *prev(it);
		}
		cout<<ans<<endl;
	}
	
}

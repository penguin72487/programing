#include<iostream>
using namespace std;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int a;
	while(cin>>a&&a)
	{
		int i=0;
		while(a&1)
		{
			a>>=1;
			i++;
		}
		cout<<i<<"\n";
	}
}


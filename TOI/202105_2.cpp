#include<iostream>
using namespace std;
int n;
class zero{
	string operators;
	int* list;
	int val()
	{
		int ans=list[0];
		for(int i=1;i<n;i++)
		{
			if(operators[i]=='+')
			{
				ans+=list[i];
			}
			else
			{
				ans-=list[i];
			}
		}
	}
	
};
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++)
	{
		cin>>list[i];
	}
	string operators;
	for(int i=0;i<n;i++)
	{
		operators.push_back('+');
	}
	
}

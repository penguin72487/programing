#include<iostream>
#include<map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	map<string,bool> num;
	while(getline(cin,s))
	{
		if(num.find(s)==num.end())
		{
			num[s]=1;
			cout<<"NO"<<"\n";		
		}
		else
		{
			cout<<"YES"<<"\n";
		}
		
	}
	
	
}

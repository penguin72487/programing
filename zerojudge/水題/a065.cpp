#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		for(int i=0;i<6;i++)
		{
			cout<<abs(s[i]-s[i+1]);
		}
		cout<<endl;
	}
}

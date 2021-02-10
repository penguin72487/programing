#include<iostream>
#include<map>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s[10];
		map<string,int> web;
		int int_max=0;
		for(int j=0;j<10;j++)
		{
			int hit;
			cin>>s[j]>>hit;
			web[s[j]]=hit;
			if(int_max<hit)
			int_max=hit;
		}
		cout<<"Case #"<<i+1<<":"<<endl;
		for(int j=0;j<10;j++)
		{
			if(web[s[j]]==int_max)
			{
				cout<<s[j]<<endl;
			}
		}
	}
}

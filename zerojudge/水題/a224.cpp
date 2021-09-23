#include<iostream>
#include<map>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		map<char,int> hui; 
		int n=s.length();
		for(int i=0;i<n;i++)
		{
			//cout<<s[i]<<endl;
			if(s[i]>='A'&&s[i]<='Z')
			{
				s[i]+=32;
				//cout<<s[i]<<endl;	
			}
			if(!(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'))
			continue;
			if(hui.find(s[i])==hui.end())
			{
				hui[s[i]]=1;
			}
			else
			{
				hui[s[i]]++;
			}
		}
		int a=0,b=0;
		for(auto it=hui.begin();it!=hui.end();it++)
		{
			if((it->second)%2)
			a++;
			else
			b++;
		}
		//cout<<a<<endl;
		if(a>1)
		cout<<"no..."<<endl;
		else if(a==b&&a==0)
		cout<<"yes !"<<endl;
		else
		cout<<"yes !"<<endl;
	//	hui.clear();
	}
	
}

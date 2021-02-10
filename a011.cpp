#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
			for(int i=0;i<s.size();i++)
		{
            if(!isalpha(s[i])) 
			s[i]=' ';

		}
		string tmp;
	int ans=0;
	
	stringstream ss(s);
	
	while(ss>>tmp)
	{
	        ans++;
	}
	cout<<ans<<endl;
		
	}




}

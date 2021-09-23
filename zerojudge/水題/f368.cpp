#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string a;
	string RED="RED",GREEN="GREEN";
	string o="0";
	while(cin>>a)
	{
		int ans=0;
		while(a.find(RED)!=string::npos)
		{
			ans++;
			a = a.replace(a.find(RED),1,o);
		}
		while(a.find(GREEN)!=string::npos)
		{
			ans++;
			a = a.replace(a.find(GREEN),1,o);
		}
	
    
	    printf("1/%g\n", pow(2,ans));
	

		
	}

	
}


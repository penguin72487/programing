#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
	string l;
	while(cin>>l)
	{
		reverse(l.begin(),l.end());
		int n=l.length();
		int i;
		for(i=0;i<n;i++)
		{	
		if(l=="0")
		cout<<"0"<<endl;
		else if(l[i]!='0')
		cout<<l[i]<<endl;
	}
	}
}

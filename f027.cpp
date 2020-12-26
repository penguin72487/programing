#include <iostream>
using namespace std;
int main()
{
	string in;
	cin>>in;
	for(int i=0;i<in.length();i++)
	{
		if(in[i]=='+')
		{
			cout<<endl;
		continue;	
		}
		
		cout<<in[i];
	}
	cout<<"\nLog in"<<endl;
} 

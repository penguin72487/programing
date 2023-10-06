#include<iostream>

#include<algorithm>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int i=0;
	
	if((count(a.begin(),a.end(),'0')+count(a.begin(),a.end(),'1'))!=a.length())
	{
		cout<<"1 ";
		i++;
	}
	if(a.length()<8||a.length()>12)
	{
		cout<<"2 ";
		i++;
	}
	if(count(a.begin(),a.end(),'0')<2)
	{
		cout<<"3 ";
		i++;
	}
	if(count(a.begin(),a.end(),'1')<3)
	{
		cout<<"4 ";
		i++;
	}
	if(a.find("101")== string::npos)
	{
		cout<<"5 ";	
		i++;
	}
	if(i==0)
	cout<<"0"<<endl;
	
}


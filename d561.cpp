#include<iostream>
#include<iomanip>
using namespace std;
string f(string a);
int main()
{
	string a;
	while(cin>>a)
	{
		cout<<f(a)<<endl;
	} 
	
	
		
}
string f(string a)
{
	string s;
	s.l
	auto it=a.begin();
	for(;*it!='.';it++)
	{
		s+=*it;
	}
	s+=*(it++);
	s+=*(it++);
	s+=*(it++);
	if(*it>'5')
	{
		it--;
		*it++;
	}
	cout<<s<<endl;
	 
	
}

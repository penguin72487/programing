#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	getline(cin,a);
	int i;
	string s_for="for",s_4="4",s_to="tp",s_2="2",s_and="and",s_n="n",s_you="you",s_u="u";
	a = a.replace(a.find(s_for),s_for.length(),s_4);
	a = a.replace(a.find(s_to),s_to.length(),s_2);
	a = a.replace(a.find(s_and),s_and.length(),s_n);
	a = a.replace(a.find(s_for),s_for.length(),s_4);
	
	
	for(i=0;i<a.size();i++)
	{
		
	}
	cout<<endl;
}

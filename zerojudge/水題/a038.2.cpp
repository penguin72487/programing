#include<iostream>
#include<algorithm>
 #include <string>
using namespace std;
int main ()
{
	string l;
	while(cin>>l)
	{
		reverse(l.begin(),l.end());
		int n=l.length();
		int a=std::stoi(l);
		cout<<a<<endl;
	
	}
}

#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
	string l,k;
	while(cin>>l)
	{
		k=l;
		reverse(k.begin(),k.end());
		
		if(l==k)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
}

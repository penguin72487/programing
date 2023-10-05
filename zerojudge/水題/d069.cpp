#include<iostream>
using namespace std;
int main()
{
	int a;
	while(cin>>a&&a!=0)
	{
		
		if(a%4!=0)
		cout<<"a normal year\n";
		else if(a%400!=0&&a%100==0)
		cout<<"a normal year\n";
		else
		cout<<"a leap year\n";
	}
}

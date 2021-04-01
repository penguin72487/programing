#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int max=76,a;
	while(cin>>a&&a!=0)
	{
		if(a%7==0&&max%7!=0)
		{
			max=a;
		}
		else if(a%7==0&&max%7==0)
		{
			if(a%70>max%70)
			{
				max=a;
			}
		}
		else if(a%7!=0&&max%7!=0)
		{
			if(a%77<max%77)
			{
				max=a;
			}
		}
		 
	}
	cout<<max;
	
}

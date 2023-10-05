#include<iostream>
using namespace std;
int main()
{
	string a;
	while(getline(cin,a))
	{
		int d=32;
		for(int i=0;i<a.length();i++)
		{
			if(a[i]==' ')
			{
			}
			else if(a[i]<91)
			{
				a[i]+=d; 
			}
		}
		for(int i=0;i<a.length();i++)
		{
			if(a[i]==' ')
			{
				continue;
			}
			for(int j=0;j<a.length();j++)
			{
				if(i==j)
				{
				 cout<<char(a[j]-d);	
				}
				else
				{
					cout<<a[j];
				}		
			}
			cout<<"\n";
		}
	}
}


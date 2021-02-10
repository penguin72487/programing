#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		bool out=0;
		int a,b,z;
		cin>>a>>b>>z;
		for(int j=a+1;j<b;j++)
		{
			if(j%z==0)
			{
				out=1;
				cout<<j<<" ";
			}
			
		}
		if(!out)
		{
			cout<<"No free parking spaces.";
		}
		cout<<"\n";
		
	} 
}

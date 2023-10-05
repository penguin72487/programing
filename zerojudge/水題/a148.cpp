#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int temp;
		int num=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			num+=temp;
		}
		if(num/n>59)
		{
			cout<<"no"<<endl;
		}
		else
		{
			cout<<"yes"<<endl;
		}
		
	}
}

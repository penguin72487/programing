#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		int m=(c-a)*60+d-b;
		if(m>=e)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
}

#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s[n+1];
	s[n]=100000;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int op;
	cin>>op;
	op--;
	int ans=op;
	int r=0,l=0;
	int i=op+1;
	while(s[i]<=s[i-1]&&i<n)
	{
	//	cout<<"1\n";
	//	cout<<"s["<< i<<"]"<<s[i]<<"\n";
		i++;
	}
	r=i-1;
	i=op-1;
	//cout<<"hi\n";
	while(s[i]<=s[i+1]&&i>-1)
	{
		
		//cout<<"2\n";
		//cout<<"s["<< i<<"]"<<s[i]<<"\n";
		i--;
	}
	l=i+1;
	if(s[l]<s[r])
	{
		cout<<l+1<<"\n";
	}
	else
	{
		cout<<r+1<<"\n";
	}
}


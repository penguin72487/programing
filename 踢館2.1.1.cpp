#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<char> l;
	int k[n+1]={0};
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>l;
		k[i]=l.size();
	}
	cout<<l<<endl;
	int r,c;
		for(i=1;i<=n;i++) 
	{
		cin>>r>>c;
		reverse(l.begin()+k[i-1]+r,l.begin()+k[i-1]+c);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+k[i-1];j<k[i];j++)
		{
			cout<<l[j];
		}
		cout<<" ";
	}
	 
}

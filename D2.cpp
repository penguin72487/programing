#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,i,a,b,w;
	for(cin>>t;t>0;t--)
	{
		cin>>a>>b>>w;
		if (max(a,b)-min(a,b)>=4&&max(a,b)==22)
		cout<<"YES\n";
		else if (max(a,b)-min(a,b)>=4&&max(a,b)>=22)
		cout<<"NO\n";
		else if(max(a,b)-min(a,b)>=4&&max(a,b)-min(a,b)<22)
		cout<<"YES\n";
		else if(max(a,b)-min(a,b)>=2&&max(a,b)>=33)
		cout<<"YES\n";
		else 
		cout<<"NO\n";		
	}
}

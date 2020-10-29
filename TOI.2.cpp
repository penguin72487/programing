#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int o;
	cin>>o;
	string p;
	cin>>p;
	reverse(p.begin(),p.end());
	int n=p.length();
	int i,j,l[(n+n-1)/n]={0};
	int k[(n+n-1)/n];
	int m;
	cout<<p<<endl;
	for(i=0;i<(n+n-1)/n;i++)
	{
		for(j=i*n;j<n;j++)
		{
			l[i]+=p[j]-'0';
			k[i]=l[i];
			m=max(m,k[i]);
		}
	}
		for(i=0;i<(n+n-1)/n;i++)
		cout<<i+1<<" "<<l[i]<<endl;
		for(i=0;i<(n+n-1)/n;i++)
		{
			if(k[i]==m)
			cout<<i+1<<" "<<l[i]<<endl;
		}
	
}

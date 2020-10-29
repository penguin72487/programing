#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string p;
	cin>>p;
	reverse(p.begin(),p.end());
	int o=p.length();
	int i,j,l[(p.length()+n-1)/n]={0};
	int k[(p.length()+n-1)/n];
	int m;
	cout<<p<<endl;
	for(i=0;i<(p.length()+n-1)/n;i++)
	{
		for(j=i*n;j<(i<=p.length()/n)*n+(i>p.length()/n)*(p.length()%n);j++)
		{
			l[i]+=p[j]-'0';
			k[i]=l[i];
			m=max(m,k[i]);
			o-=(i+1)*n ;
			
		}
	}
		for(i=0;i<(p.length()+n-1)/n;i++)
		cout<<i+1<<" "<<l[i]<<endl;
		for(i=0;i<(p.length()+n-1)/n;i++)
		{
			if(k[i]==m)
			cout<<i+1<<" "<<l[i]<<endl;
		}
	
}

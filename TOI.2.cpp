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
	int i,j,l[(n+o-1)/o]={0};
	int k[(n+o-1)/o];
	int m;
	//cout<<p<<endl;
	for(i=0;i<(n+o-1)/o;i++)
	{
		for(j=i*o;j<o+i*o;j++)
		{
			if(j>=n)
			break;
			l[i]+=p[j]-'0';
			k[i]=l[i];
			m=max(m,k[i]);
		}
	}
	//	for(i=0;i<(n+o-1)/o;i++)
		//cout<<i+1<<" "<<l[i]<<endl;
		for(i=0;i<(n+o-1)/o;i++)
		{
			if(k[i]==m)
			cout<<i+1<<" "<<l[i]<<endl;
		}
	
}

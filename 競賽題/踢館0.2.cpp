#include <iostream>
using namespace std;
int main ()
{
	int a[10000],b,c=0,i=0,n;
	for (cin>>n;i<n;i++)
	cin>>a[i];
	cin>>b;
	for(i=0;i<n;i++)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(a[j]-a[i]==b)
				cout<<"Yes"<<"\n"<<i<<" "<<j<<endl;
				c=c+(a[j]-a[i]==b);
		}
	}
	if(c==0)
	cout<<"No"<<endl;
}

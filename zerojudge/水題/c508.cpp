#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int l[n];
	int i;
	for(i=0;i<n;i++)
	cin>>l[i];
	sort(l,l+n);
	for(i=0;i<n;i++)
	cout<<l[i]<<" ";
	cout<<endl;
	for(i=0;i<n;i++)
	{
		if(l[n-i]!=l[n-i-1])
			cout<<l[n-i-1]<<" ";
			
	}

	cout<<endl;
	
	
}

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string l;
	int k[n+1]={0};
	int i,j,r,c;
	string a;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		l+=a;
		k[i]=l.length();
	 }	
			for(i=0;i<n;i++)
	{
		 cin>>r>>c;
		 reverse(l.begin()+k[i]+r-1,l.begin()+k[i]+c);
		 for(j=k[i];j<k[i+1];j++)
			 {
			 	cout<<l[j];
			 }
			if(i!=n-1)
		 	cout<<" ";
		 	else
		 	cout<<".";
	 }
		 
	
}

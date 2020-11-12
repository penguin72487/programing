#include<iostream>

using namespace std;
main()
{
	int n;
	cin>>n;
   string a;
   int i,j;
   for(i=0;i<n;i++)
   {
   		int ans=1;
   		cin>>a;
   		for(j=0;j<a.length();j++)
   		ans*=a[j]-'0';
    	cout<<ans<<endl;
   	
   }
   
   
}

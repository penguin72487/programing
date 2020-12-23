#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int fn_grup(bool gp[],int loc[],int i);
int temp=0;
int main()
{
	 int n,m,ans=0;
	 cin>>n;
	 int loc[n+1];
	 int i,j;
	 for(i=1;i<=n;i++)
	 {
	 	cin>>loc[i];
	 }
	 for(i=1;i<=n;i++)
	 {
	 	bool gp[n+1]={0};
	 	if(loc[i]!=i)
	 	{
	 		ans++;
			m=fn_grup(gp,loc,i);
			cout<<"ans: "<<ans<<" \n";
			cout<<"m: "<<m<<" \n";
			for(j=i+1;j<=m;j++)
			{
				cout<<loc[j]<<" ";
			}
			cout<<loc[i]<<endl;
			
			
			
			cout<<ans<<endl;
		}
		i=m;
	 	
	 	
	 	
	 	
	 }
	 
	 
} 
 fn_grup(bool gp[],int loc[],int i)
 {
 	
 	if(gp[i]==1)
 	{
 		
 		return temp;	
	}
 	
 	else
 	{
 		gp[i]=1;
 		temp=max(temp,i);
	}
	cout<<"i: "<<i<<endl;
 	return fn_grup(gp,loc,loc[i]);
 }

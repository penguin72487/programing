#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
int fn_grup(bool gp[],int loc[],int i);
int temp=0;
stringstream out;
vector <int> num;
int main()
{
	 
	 int n,m,ans=0;
	 cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	{
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
				reverse(num.begin(),num.end());
				out<<m-i+1<<" ";
				for(j=0;j<m-i+1;j++)
				{
					out<<num[j]<<" ";
				}
				out<<"\n";
				num.clear();
				i=m;
			}
			temp=0;
	 	}
	 	cout<<ans<<" \n";
	 	cout<<out.str()<<endl;
	 
	 
	}
	 
} 
int fn_grup(bool gp[],int loc[],int i)
 {
 	
 	if(gp[i]==1)
 	{
 		num.push_back(num[0]);
 		return temp;	
	}
 	
 	else
 	{
 		gp[i]=1;
 		temp=max(temp,i);
	}
	
	num.push_back(i);
 	return fn_grup(gp,loc,loc[i]);
 }

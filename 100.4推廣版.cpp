#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <unsigned long> ans;
int i,j,k,o;
unsigned long l[100];
unsigned long f(int n)
{

	if(n==0||n==1)
	return 1;
	if(l[n]!=0)
	return l[n];
	return l[n]=f(n-1)*n ;
}
int main ()
{
	ans.push_back(1);
	 for(i=1;i<=100;i++)
		{
			for(o=100-i;o>=0;o--)
			{
				for(k=0;k<ans.size();k++)
			{
				ans[k]*=i;
				//cout<<ans[k]<<" "<<i<<" ";
				
			}
				
			
		for(j=0;j<ans.size();j++)						//統一進位 
			{
				if(ans[j]>9)
		 	{
		 		if(ans.size()==j+1)
		 			ans.push_back(ans[j]/10);
		 		else
    				ans[j+1]+=ans[j]/10;
    			ans[j]=ans[j]%10;
   			}
   		
	}
				
			}
			
		}
			reverse(ans.begin(),ans.end());
	i=0;
	while(ans[i]==0)
	i++;
			
	for(;i<ans.size();i++)
	cout<<ans[i];
	cout<<endl;
	ans.clear();
		
}

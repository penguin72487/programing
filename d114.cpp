#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> ans;
int i,j,k,o;
int main ()
{
	ans.push_back(1);
	 for(i=2;i<=100;i++)
		{
			for(o=100-i;o>=0;o--)
			{
				for(k=0;k<ans.size();k++)
			{
				if(ans[k]!=0)
				ans[k]*=i;
				//cout<<ans[k]<<" "<<i<<" ";
				
			}
				
			
		for(j=0;j<ans.size();j++)						//�Τ@�i�� 
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
	i=0;				//�O�I�h0�Y 
	while(ans[i]==0)
	i++;
			
	for(;i<ans.size();i++)
	cout<<ans[i]<<endl;
	cout<<endl;
	ans.clear();
		
}






#include<iostream>
#include<vector>//vector陣列 
#include<algorithm>//reverse 
using namespace std;
vector <unsigned long> ans;
unsigned long i,j,k,o,m,num;
int main ()
{
	int a;
	while(cin>>a)
	{
 	m=0;
		num=0;
		ans.push_back(1);
	 	for(i=1;i<=a;i++)
		{
			//cout<<i<<" ";
			for(j=0;j<ans.size();j++)
			ans[j]*=i; 
		
			
				
			
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
	reverse(ans.begin(),ans.end());
	i=0;
	while(ans[i]==0)  //去數字頭的0 
	i++;
	printf("%d",ans.size()-i);
	//printf("\n總共是%d位數\n",ans.size()-i);		
	//for(;i<ans.size();i++)
	//printf("%d",ans[i]);
	//printf("\n");
//	printf("總共是%d位數",ans.size()-i);
	ans.clear();
	}
	
	
		
}

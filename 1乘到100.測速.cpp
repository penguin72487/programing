#include<iostream>
#include<vector>//vector陣烈 
#include<algorithm>//reverse 
using namespace std;
vector <unsigned long> ans;
int i,j,k,o;
int main ()
{
	int a=500;
	
		ans.push_back(1);
	 for(i=1;i<=a;i++)//1! 乘到100!就是1乘 100次，2乘99次...100乘1次 
		{
			int m=0;
			printf("%d ",i); 
			int num = i-1;
			while(num>5)
			{
				m+=num/5;
				num/=5;
				//cout<<num<<" ";
			}
			
			for(o=a-i;o>=0;o--)  //控制i要乘多少次 
			{
			
			
				for(k=m;k<ans.size();k++)
			{
				if(ans[k]!=0)
				{
						ans[k]*=i;
					
				} 
			    //debug用 
				
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
	while(ans[i]==0)  //去數字頭的0 
	i++;
			
	for(;i<ans.size();i++)
	printf("%d",ans[i]);
	printf("\n");
	ans.clear();
	
		
}

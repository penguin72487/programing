#include<iostream>
#include<vector>//vector�}�P 
#include<algorithm>//reverse 
using namespace std;
vector <unsigned long> ans;
int i,j,k,o;
int main ()
{
	int a=500;
	
		ans.push_back(1);
	 for(i=1;i<=a;i++)//1! ����100!�N�O1�� 100���A2��99��...100��1�� 
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
			
			for(o=a-i;o>=0;o--)  //����i�n���h�֦� 
			{
			
			
				for(k=m;k<ans.size();k++)
			{
				if(ans[k]!=0)
				{
						ans[k]*=i;
					
				} 
			    //debug�� 
				
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
	i=0;
	while(ans[i]==0)  //�h�Ʀr�Y��0 
	i++;
			
	for(;i<ans.size();i++)
	printf("%d",ans[i]);
	printf("\n");
	ans.clear();
	
		
}

#include<iostream>
#include<vector>//vector皚 
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
	 for(i=1;i<=a;i++)//1! 100!碞琌1 100Ω299Ω...1001Ω 
		{
			int tum =i;
			int t =0;//舦 
			while(tum%5==0)
			{
				t++;
				tum/=5;
			}
			
			printf("%d ",i);
			for(o=a-i+1;o>0;o--)  //北i璶ぶΩ 
			{
				m=num+t*(a-i+1-o);
			
				for(k=m;k<ans.size();k++)
			{
				 //	printf("%d",ans[k]); 
				if(ans[k]!=0)
				{
						ans[k]*=i;	
				} 
			}
				
			
		for(j=m;j<ans.size();j++)						//参秈 
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
			num=m;
			
		}
	reverse(ans.begin(),ans.end());
	i=0;
	while(ans[i]==0)  //计繷0 
	i++;
	printf("\n羆琌%d计\n",ans.size()-i);		
	for(;i<ans.size();i++)
	printf("%d",ans[i]);
	printf("\n");
//	printf("羆琌%d计",ans.size()-i);
	ans.clear();
	}
	
	
		
}

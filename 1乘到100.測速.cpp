#include<iostream>
#include<vector>//vector�}�C 
#include<algorithm>//reverse 
using namespace std;
vector <unsigned long> ans;
unsigned long i,j,k,o,m,num;
int main ()
{
	int a=100;

		m=0;
		num=0;
		ans.push_back(1);
	 for(i=1;i<=a;i++)//1! ����100!�N�O1�� 100���A2��99��...100��1�� 
		{
			int tum =i;
			int t =0;//�[�v 
			while(tum%5==0)
			{
				t++;
				tum/=5;
			}
			
			printf("%d ",i);
			for(o=a-i+1;o>0;o--)  //����i�n���h�֦� 
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
				
			
		for(j=m;j<ans.size();j++)						//�Τ@�i�� 
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
	while(ans[i]==0)  //�h�Ʀr�Y��0 
	i++;
			
	for(;i<ans.size();i++)
	printf("%d",ans[i]);
	printf("\n");
	ans.clear();
		
}

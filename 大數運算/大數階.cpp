#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <unsigned long> factorial;
int i,j,k;

void  f(int n,int m)
{
	
	factorial.push_back(1);
	 for(i=1;i<=n;i++)
		{
			for(k=0;k<factorial.size();k++)
			{
				factorial[k]*=m;
				//cout<<factorial[k]<<" "<<i<<" ";
				
			}
				
			
		for(j=0;j<factorial.size();j++)						//統一進位 
			{
				if(factorial[j]>9)
		 	{
		 		if(factorial.size()==j+1)
		 			factorial.push_back(factorial[j]/10);
		 		else
    				factorial[j+1]+=factorial[j]/10;
    			factorial[j]=factorial[j]%10;
   			}
   		
	}
		}
	reverse(factorial.begin(),factorial.end());
			
}
void out()
{
		i=0;
	while(factorial[i]==0)  //去數字頭的0 
	i++;
			
	for(;i<factorial.size();i++)
	printf("%d",factorial[i]);
	printf("\n");
	factorial.clear();
}
int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
		f(m,n);
		out();
	}
	
}

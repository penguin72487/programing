#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n+=2;
	int l[n],k[n];
	l[0]=-1;
	k[0]=-1;
	l[n-1]=-1;
	k[n-1]=-1;
	int i,j;
	int m=0;
	for(i=1;i<n-1;i++)
	{
		cin>>l[i];
	}
	for(i=1;i<n-1;i++)
	{
		cin>>k[i];
	}
	
	for(i=1;i<n;i++)
	{
		int int_max=0,int_min=100;
		
		if(l[i]==-1&&l[i-1]!=-1&&l[i-2]!=-1)
		{
			cout<<"i "<<i<<endl;
			int max_num=m+1,min_num=i-1;
			for(j=1+m;j<i;j++)
			{
				if(l[j]<=int_min)
				{
					int_min=l[j];
					min_num=j;
				}
				
				if(l[j]>=int_max)
				{
					int_min=l[j];
					max_num=j;
					cout<<"max"<<endl;
				}
					
				
			}
			cout<<max_num<<" "<<min_num<<endl;
			k[max_num]^=k[min_num]^=k[max_num]^=k[min_num];
			
			m+=i;
		}
		
	}
	
	
	
	
		for(i=1;i<n-1;i++)
	{
		cout<<k[i]<<" ";
	}
	cout<<endl;
	
	
	
}

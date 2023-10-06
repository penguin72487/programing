#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	int b_num[500001]={0},king_num[500001]={0};//B的跟殿王的 
	int num=n;//蝴蝶還在的數量 
	int out[n];
	for(i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		out[i]=temp;
		b_num[temp]++;
	}
	
	for(i=0;i<m;i++)
	{
		bool t;//買1還是飛走0 
		int k;//蝴蝶編號
		cin>>t>>k;
		if(t==1)
		{
			king_num[k]++;
		}
		else if(t==0&&king_num[k]>=1)
		{
			king_num[k]--;
		} 
		else if(t==0&&king_num[k]==0&&b_num[k]>=1)
		{
			b_num[k]--;
			num--;
			
		}
		else if(t==0&&king_num[k]==0)
		{
		
		}
	}
	cout<<num<<endl;
	for(i=0;i<n;i++)
	{
		if(b_num[out[i]]>0)
		{
		
				cout<<out[i]<<" ";
				b_num[out[i]]--;
				
			
		}
		
	}
return 0;	
}

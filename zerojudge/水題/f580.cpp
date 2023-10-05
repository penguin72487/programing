#include<iostream>
using namespace std;

int main()
{
	
	int n,m;
	cin>>n>>m;
	int up[n],down[n],list[n];
	int d[n][4]={5,1,2,6};
	for(int i=0;i<n;i++)
	{
		list[i]=i;
		up[i]=3;
		down[i]=4;
		for(int j=0;j<4;j++)
		{
			d[i][j]=(j==0)*1+(j==1)*2+(j==2)*6+(j==3)*5;
		}

	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(b>0)
		{
			a--;
			b--;
			list[a]^=list[b]^=list[a]^=list[b];
		}
		else if(b==-1)
		{
			a--;
			int temp=d[list[a]][0];
			d[list[a]][0]=up[list[a]];
			up[list[a]]=down[list[a]];
			down[list[a]]=temp;
		}
		else
		{
			a--;
			int temp=d[list[a]][0];
			d[list[a]][0]=d[list[a]][3];
			d[list[a]][3]=d[list[a]][2];
			d[list[a]][2]=d[list[a]][1];
			d[list[a]][1]=temp;
		}
		printf("==========================\n%d\n%d %d %d %d\n%d\n==========================\n",up[list[a]],d[list[a]][0],d[list[a]][1],d[list[a]][2],d[list[a]][3],down[list[a]]);
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<d[list[i]][0]<<" ";
	}
	
	
}


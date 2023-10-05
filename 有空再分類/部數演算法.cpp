#include<iostream>
#include<algorithm>
using namespace std;
	int n,r,c;
	
	char l[200][200]; 
	int k[200][200];
	int i,j,o;
	int f(int int_i,int int_j)
{
	if(l[i][j]=='Y')
	return 0;
	if(l[i][j]=='\0')
	return k[i][j]=f(i,j)+1;
	if(l[i][j]!=0)
	return k[i][j]=min(f(i,j),min(f(i,j),min(f(i,j),f(i,j))));
}


int main()
{
	cin>>n>>r>>c;
	char l[r][c]; 
	int k[r][c];
	for(o=0;0<n;o++)
	{ 
		
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cin>>l[i][j];
	}
			for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(l[i][j]='*')
			k[i][j]=-1;
			if(l[i][j]='Y')
			k[i][j]=0;
		}  
	}
			for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		
		{
			cout<<k[i][j]<<" ";
		}
		cout<<endl;
	}
			for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			k[i][j]=f(i,j);
		}  
	}	
		for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		
		{
			cout<<l[i][j];
		}
		cout<<endl;
	}
	
	
	
	
	} 
	
 } 

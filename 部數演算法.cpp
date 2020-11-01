#include<iostream>
using namespace std;
	int n,r,c;

	char l[200][200]; 
	int i,j,o;
void step()
{
	int k[r][c];
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
			cin>>l[i][j];
		}  
	}
	
	
}
int main()
{
	cin>>n>>r>>c;

	for(o=0;0<n;o++)
	{ 
		
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cin>>l[i][j];
	}
		step();

	
	
	
	} 
	
 } 

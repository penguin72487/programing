#include<iostream>
using namespace std;
	int n,r,c;

	
	int i,j,o;
int stap(int i_begin,int j_begin,int i_end,int j_end)
{
	int k[r][c]={0};
	
	
	
}
int main()
{
	cin>>n>>r>>c;
	char l[r][c]; 
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
				if(l[i][j]='Y')
				stap(i,j);
			} 
	}
	 
	
	
	
	} 
	
 } 

#include<iostream>
#include<algorithm>
using namespace std;
int s[10][10] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 1, 1, 0, 1, 1, 1},
{1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
{1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
{1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 0, 1, 0, 1, 0, 0, 1, 1},
{1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int n,m;
int stp(int x,int y);
int main()
{

//	cin>>n>>m;
	//char s[n+2][m+2];
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1)
				s[i][j]=1;
			else
				cin>>s[i][j];	
		}	
	}
	/*
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
				cout<<s[i][j];	
		}	
		cout<<"\n";
	}
	*/
	cout<<stp(1,1)<<endl;
} 
int stp(int x,int y)
{
	s[x][y]=1;

	if(s[x-1][y]!=1)
	{
		return stp(x-1,y)+1;
	}
	if(s[x+1][y]!=1)
	{
		return stp(x+1,y)+1;
	}
	if(s[x][y-1]!=1)
	{
		return stp(x,y-1)+1;
	}
	if(s[x][y+1]!=1)
	{
		return stp(x,y+1)+1;
	}
	if(x==n&&y==m)
	return 1;
}

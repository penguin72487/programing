#include<iostream>
#include<algorithm>
using namespace std;
int step[10][10]={0};
int n,m;
int step(int x,int y);
int main()
{

	cin>>n>>m;
	char s[n+2][m+2];
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1)
				s[i][j]='#';
			else
				cin>>s[i][j];	
		}	
	}
	
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
				cout<<s[i][j];	
		}	
		cout<<"\n";
	}
		
} 
int step(int x,int y)
{
	if(s[x][y]=='#')
	return 1000;
	if(step[x][y])
	return step[x][y];
	if(x==n&&y==m)
	return 1;
	return min
}

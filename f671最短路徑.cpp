#include<iostream>
using namespace std;
int main()
{
	int n,m;
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

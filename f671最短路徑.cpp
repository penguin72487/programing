#include<iostream>
#include<algorithm>
using namespace std;
char s[10][10]={0};
int n,m;
int stp(int x,int y);
int main()
{

	cin>>n>>m;
	//char s[n+2][m+2];
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
	cout<<stp(1,1)+2<<endl;
} 
int stp(int x,int y)
{
	cout<<x<<" "<<y<<endl;
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
	s[x][y]=32;
	int a=100000000,b=100000000,c=100000000,d=100000000;
	if(s[x-1][y]!='#'&&s[x-1][y]!=' ')
	{
		a=stp(x-1,y)+1;
		s[x][y]='.';
	//	cout<<a<<endl;
	}
	if(s[x+1][y]!='#'&&s[x+1][y]!=' ')
	{
		b=stp(x+1,y)+1;
		s[x][y]='.';
	//	cout<<b<<endl;
	}
	if(s[x][y-1]!='#'&&s[x][y-1]!=' ')
	{
		c=stp(x,y-1)+1;
		s[x][y]='.';
	//	cout<<c<<endl;
	}
	if(s[x][y+1]!='#'&&s[x][y+1]!=' ')
	{
		d=stp(x,y+1)+1;
		s[x][y]='.';
	//	cout<<d<<endl;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
	if(x==n&&y==m)
	return min(min(a,b),min(c,d))+1;
	return 100000000;
}

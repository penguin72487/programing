#include<iostream>
#include<algorithm>
using namespace std;
int mazesol(int x,int y);
	char maze[101][101];
	int maze2[101][101]={1000};
	int n;
int main()
{
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>maze[i][j];
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(maze[i][j]=='#')
			maze2[i][j]=1000;
			else
			maze2[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<maze[i][j];
		}
		cout<<"\n";
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(maze2[i][j]==0)
			cout<<"000";
			cout<<maze2[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	n-=2;
	int ans=mazesol(n,n);
	if(ans>=1000)
	cout<<"No solution!"<<endl;
	else
	cout<<ans<<endl; 
}
int mazesol(int x,int y)
{

	//cout<<x<<" "<<y<<endl;
	if(maze2[x][y]!=0)
	{
		return maze2[x][y]+1;
	}
	if(maze[x][y]=='#')
	{
		return 1000;
	}
	else if(x==1&&y==1)
	{
		 
		return 1;
	}
	maze[x][y]='#';
	int u,d,l,r;
	d=mazesol(x+1,y);
	u=mazesol(x-1,y);
	l=mazesol(x,y-1);
	r=mazesol(x,y+1);
	maze[x][y]='.';
	return maze2[x][y]=min(min(u,d),min(r,l))+1;
	

}


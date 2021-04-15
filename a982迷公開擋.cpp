#include<iostream>
#include<algorithm>
#include<fstream>
#include<queue> 
using namespace std;
struct step;
int mazesol(int x,int y);
queue<step> list;
	char maze[100][100];
	int maze2[100][100]={1000};
	int n;
int main()
{
	fstream file;
	file.open("°g®c1.txt");
	file>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			file>>maze[i][j];
		}
	}
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
	/*
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
	cout<<mazesol(n,n)<<endl;
}
int mazesol(int x,int y)
{

	cout<<x<<" "<<y<<endl;
	
	if(maze2[x][y]!=0)
	{
		return maze2[x][y];
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
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<n+2;j++)
		{
			cout<<maze[i][j];
		}
		cout<<"\n";
	}
	int u,d,l,r;
	d=mazesol(x+1,y);
	u=mazesol(x-1,y);
	l=mazesol(x,y-1);
	r=mazesol(x,y+1);
	maze[x][y]='.';
	return maze2[x][y]=min(min(u,d),min(r,l))+1;
	

}
struct step{
	int x;
	int y;
};


#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n+=2;
	char maze[n][n];
	int maze2[n][n]={0};
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			cin>>maze[i][j];
		}
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(maze[i-1][j-1]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i-1][j]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i-1][j+1]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i][j+1]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i+1][j+1]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i][j]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i+1][j]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i+1][j-1]=='*')
			{
				maze2[i][j]++;
			}
			if(maze[i][j-1]=='*')
			{
				maze2[i][j]++;
			}
			
		}
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(maze2[i][j]==0)
			{
				cout<<"-";
			}
			else if(maze[i][j]=='*')
			{
				cout<<"*";
			}
			else
			{
				cout<<maze2[i][j];
			}
			
		}
		cout<<"\n";
	}	

}


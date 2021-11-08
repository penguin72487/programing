#include<iostream>
using namespace std;
int main()
{

	char maze[17][32];
	int maze2[17][32]={0};
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<32;j++)
		{
			maze[i][j]='.';
		}
	}
	for(int i=1;i<16;i++)
	{
		for(int j=1;j<31;j++)
		{
			cin>>maze[i][j];
		}
	}
	for(int i=1;i<16;i++)
	{
		for(int j=1;j<31;j++)
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
	for(int i=1;i<16;i++)
	{
		for(int j=1;j<31;j++)
		{
			if(maze2[i][j]==0)
			{
				cout<<".";
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


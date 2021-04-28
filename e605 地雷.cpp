#include<iostream>
using namespace std;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
	int t=0;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
		t++;
		n+=2;
		m+=2;
		char maze[n][m];
		int maze2[n][m]={0};
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<m-1;j++)
			{
				maze[i][j]='.';
			}
		}
		for(int i=1;i<n-1;i++)
		{
			for(int j=1;j<m-1;j++)
			{
				cin>>maze[i][j];
			}
		}
		for(int i=1;i<n-1;i++)
		{
			for(int j=1;j<m-1;j++)
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
		cout<<"Field #"<<t<<":\n"; 
		for(int i=1;i<n-1;i++)
		{
			for(int j=1;j<m-1;j++)
			{
				if(maze[i][j]=='*')
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
	
}


#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
struct step{
	int x;
	int y;
};

queue<step> list;
	char maze[1000][1000];
	int maze2[1000][1000]={0};
	int n;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false); 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>maze[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			maze2[i][j]=1000;
		}
	}
	n-=2;
	
	{
		step temp;
		temp.x=1;
		temp.y=1;
		list.push(temp);
		maze2[1][1]=1;
		if(maze[1][2]!='#')
		{
			maze2[1][2]=2;
			step temp;
			temp.x=1;
			temp.y=2;
			list.push(temp);
		}
		
		if(maze[1][0]!='#')
		{
				maze2[1][0]=2;
				step temp;
			temp.x=1;
			temp.y=0;
			list.push(temp);
		}
		if(maze[2][1]!='#')
		{
				maze2[2][1]=2;
				step temp;
			temp.x=2;
			temp.y=1;
			list.push(temp);
		}
		if(maze[0][1]!='#')
		{
				maze2[0][1]=2;
				step temp;
			temp.x=0;
			temp.y=1;
			list.push(temp);
		}
	}
	
	while(list.empty()==0)
	{

		int x=list.front().x;
		int y=list.front().y;
		if(x==1&&y==1)
		maze2[x][y]=1;
		else
		maze2[x][y]=min(min(maze2[x-1][y],maze2[x+1][y]),min(maze2[x][y-1],maze2[x][y+1]))+1;
		
		
		if(x==n&&y==n)
		{
			break;
		}
		if(maze[x][y+1]!='#'&&maze2[x][y+1]>maze2[x][y])
		{
			step temp;
			temp.x=x;
			temp.y=y+1;
			list.push(temp);
		}
	
		if(maze[x][y-1]!='#'&&maze2[x][y-1]>maze2[x][y])
		{
			step temp;
			temp.x=x;
			temp.y=y-1;
			list.push(temp);
		}

		if(maze[x+1][y]!='#'&&maze2[x+1][y]>maze2[x][y])
		{
			step temp;
			temp.x=x+1;
			temp.y=y;
			list.push(temp);
		}

		if(maze[x-1][y]!='#'&&maze2[x-1][y]>maze2[x][y])
		{
			step temp;
			temp.x=x-1;
			temp.y=y;
			list.push(temp);
		}

		list.pop();

	}
	if(list.empty())
	cout<<"No solution!"<<endl;
	else
	{
		cout<<maze2[n][n]<<endl;
	}
}


#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
struct step{
	int x;
	int y;
};


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; 
	cin>>n;
	n+=2;
	queue<step> list;
	char maze[n][n];
	int maze2[n][n]={0};
	int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0||j==0||i==n-1||j==n-1)
			{
				maze[i][j]='#';
			}
			else
			{
				cin>>maze[i][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			maze2[i][j]=1000000;
		}
	}
	step op;
	op.x=1;
	op.y=1;
	list.push(op);
	while(!list.empty())
	{
		int x=list.front().x;
		int y=list.front().y;
		//cout<<x<<" "<<y<<"\n";
		list.pop();
		if(x==n-2&&y==n-2)
		{
			maze2[x][y]=min(min(maze2[x-1][y],maze2[x+1][y]),min(maze2[x][y-1],maze2[x][y+1]))+1;
			break;
		}
		if(x==1&&y==1)
		maze2[x][y]=0;
		else
		maze2[x][y]=min(min(maze2[x-1][y],maze2[x+1][y]),min(maze2[x][y-1],maze2[x][y+1]))+1;
		
		for(int k=0;k<4;k++)
		{
			if(maze[x+dx[k]][y+dy[k]]!='#'&&maze2[x+dx[k]][y+dy[k]]>maze2[x][y])
			{
				step temp;
				temp.x=x+dx[k];
				temp.y=y+dy[k];
				list.push(temp);
			}
		}
	
	}
	if(maze2[n-2][n-2]==1000000)
	cout<<"-1"<<"\n";
	else
	{
		cout<<maze2[n-2][n-2]<<"\n";
	}
}


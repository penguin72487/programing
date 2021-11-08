#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
class step{
public :
	int x;
	int y;
	step(int xt,int yt)
	{
		x=xt;
		y=yt;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	n+=2;
	m+=2;
	char maze[n][m];
	int maze2[n][m];
	fill(maze[0],maze[n-1]+m,'#');
	fill(maze2[0],maze2[n-1]+m,2147483647);

	for(int i=1;i<n-1;++i)
	{
		for(int j=1;j<m-1;++j)
		{
			cin>>maze[i][j];
		}
	}

	deque<step> list;
	step op(1,1);
	list.push_back(op);
	while(!list.empty())
	{
	
		
		step now=list.front();
		int x=now.x;
		int y=now.y;
		list.pop_front();
		if(x==n-2&&y==m-2)
 		{
 		  	maze2[x][y]=min(min(maze2[x-1][y],maze2[x+1][y]),min(maze2[x][y-1],maze2[x][y+1]))+1;
  			break;
  		}
  		if(x==1&&y==1)
  		maze2[x][y]=0;
  		else
  		maze2[x][y]=min(min(maze2[x-1][y],maze2[x+1][y]),min(maze2[x][y-1],maze2[x][y+1]))+1;
		
		int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
		for(int i=0;i<4;i++)
		{
			if(maze[x+dx[i]][y+dy[i]]!='#'&&maze2[x+dx[i]][y+dy[i]]>maze2[x][y])
			{
				step temp(x+dx[i],y+dy[i]);
			    list.push_back(temp);
			}
		}
		
	}

	if(maze2[n-2][m-2]==2147483647)
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<maze2[n-2][m-2]<<"\n";
	}
}

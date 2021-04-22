#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
struct step{
	int x;
	int y;
};

queue<step> list;
	int maze[1000][1000];
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
	int* x=new int;
	int* y=new int;
	cin>>*x>>*y;
	
	n-=2;
	
	{
		step temp;
		temp.x=*x;
		temp.y=*y;
		list.push(temp);
		maze2[*x][*y]=1;
		if(abs(maze[*x][*y+1]-maze[*x][*y])<3&&maze2[*x][*y+1]>maze2[*x][*y])
		{
			step temp;
			temp.x=*x;
			temp.y=*y+1;
			list.push(temp);
		}
	
		if(abs(maze[*x][*y-1]-maze[*x][*y])<3&&maze2[*x][*y-1]>maze2[*x][*y])
		{
			step temp;
			temp.x=*x;
			temp.y=*y-1;
			list.push(temp);
		}

		if(abs(maze[*x+1][*y]-maze[*x][*y])<3&&maze2[*x+1][*y]>maze2[*x][*y])
		{
			step temp;
			temp.x=*x+1;
			temp.y=*y;
			list.push(temp);
		}

		if(abs(maze[*x-1][*y]-maze[*x][*y])<3&&maze2[*x-1][*y]>maze2[*x][*y])
		{
			step temp;
			temp.x=*x-1;
			temp.y=*y;
			list.push(temp);
		}
	}
	int st_x=*x,st_y=*y;
	delete x;
	delete y;
	while(list.empty()==0)
	{

		int x=list.front().x;
		int y=list.front().y;
		if(x==st_x&&y==st_y)
		maze2[x][y]=1;
		else
		maze2[x][y]=min(min(maze2[x-1][y],maze2[x+1][y]),min(maze2[x][y-1],maze2[x][y+1]))+1;
		
		
		if(abs(maze[x][y+1]-maze[x][y])<3&&maze2[x][y+1]>maze2[x][y])
		{
			step temp;
			temp.x=x;
			temp.y=y+1;
			list.push(temp);
		}
	
		if(abs(maze[x][y-1]-maze[x][y])<3&&maze2[x][y-1]>maze2[x][y])
		{
			step temp;
			temp.x=x;
			temp.y=y-1;
			list.push(temp);
		}

		if(abs(maze[x+1][y]-maze[x][y])<3&&maze2[x+1][y]>maze2[x][y])
		{
			step temp;
			temp.x=x+1;
			temp.y=y;
			list.push(temp);
		}

		if(abs(maze[x-1][y]-maze[x][y])<3&&maze2[x-1][y]>maze2[x][y])
		{
			step temp;
			temp.x=x-1;
			temp.y=y;
			list.push(temp);
		}
	}

		list.pop();

	
	//if(list.empty())
	//cout<<"No solution!"<<endl;
	
	{
		int ans;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans=max(maze2[i][j],ans);
			}
		}
		cout<<ans<<endl;
	}
}


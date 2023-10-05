#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
struct step{
	int x;
	int y;
};

queue<step> list;
	int maze[1001][1001];
	int maze2[1001][1001]={0};
	int n;
int main()
{
	//cin.tie(0);
	ios_base::sync_with_stdio(false); 
	cin>>n;
	int* x=new int;
	int* y=new int;
	cin>>(*x)>>(*y);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>maze[i][j];
		}
	}
	//cout<<"**"<<*x<<" "<<*y<<endl; 
	//n-=2;
	
	{
		step temp;
		temp.x=*x;
		temp.y=*y;
		list.push(temp);
	}

	delete x;
	delete y;
	while(list.empty()==0)
	{

		int x=list.front().x;
		int y=list.front().y;
		//cout<<x<<" "<<y<<endl; 
		if(x<0||y<0||x>=n||y>=n)
		{
			list.pop();
			continue;
		}
		if(maze2[x][y]==1)
		{
			list.pop();
			continue;
		}
		maze2[x][y]=1;
		//cout<<"+++++++++++++++++1"<<endl;
		
		if(abs(maze[x][y+1]-maze[x][y])<3&&maze2[x][y+1]==0)
		{
			step temp;
			temp.x=x;
			temp.y=y+1;
			list.push(temp);
		}
	
		if(abs(maze[x][y-1]-maze[x][y])<3&&maze2[x][y-1]==0)
		{
			step temp;
			temp.x=x;
			temp.y=y-1;
			list.push(temp);
		}

		if(abs(maze[x+1][y]-maze[x][y])<3&&maze2[x+1][y]==0)
		{
			step temp;
			temp.x=x+1;
			temp.y=y;
			list.push(temp);
		}

		if(abs(maze[x-1][y]-maze[x][y])<3&&maze2[x-1][y]==0)
		{
			step temp;
			temp.x=x-1;
			temp.y=y;
			list.push(temp);
		}
		list.pop();
	}

		

	
	//if(list.empty())
	//cout<<"No solution!"<<endl;
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<maze2[i][j];
		}
		cout<<"\n";
	}
	*/
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans+=maze2[i][j];
			}
		}
		cout<<ans<<endl;
	}
}


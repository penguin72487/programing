#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
struct step{
	int x;
	int y;
};
queue<step> list;
int tube[101][101];
int tube2[101][101]={};
void bfs(int s);
void bfs();
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false); 
	int s;
	int num=0;
	while(cin>>s)
	{
		num++;
		int n,m;
		cin>>n>>m;
		//n^=m^=n^=m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>tube[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				tube2[i][j]=100000;
			}
		}
		
		int st_x=0;
		int st_y;
		for(int j=0;j<n;j++)
		{
			if(tube[0][j]==1)
			{
				st_y=j;
				break;
			}
		}
		step temp;
		temp.x=st_x;
		temp.y=st_y;

		list.push(temp);
		while(list.empty()==0)
		{
	
			int x=list.front().x;
			int y=list.front().y;
			
			cout<<x<<" "<<y<<endl; 
			
			//if(tube[x][y]=='X')
			if(x<0||y<0||x>n||y>n||tube[x][y]==0)
			{
				tube[x][y]=0;
				list.pop();
				continue;
			}
			cout<<"hi\n"<<endl;
			tube[x][y]=0;
			tube2[x][y]=0;
			if(x==st_x&&y==st_y)
			tube2[st_x][st_y]=1;
			else
			tube2[x][y]=min(min(tube2[x-1][y],tube2[x+1][y]),min(tube2[x][y-1],tube2[x][y+1]))+1;
			
			if(tube[x][y+1]==1)
			{
				step temp;
				temp.x=x;
				temp.y=y+1;
				list.push(temp);
			}
		
			if(tube[x][y-1]==1)
			{
				step temp;
				temp.x=x;
				temp.y=y-1;
				list.push(temp);
			}
	
			if(tube[x+1][y]==1)
			{
				step temp;
				temp.x=x+1;
				temp.y=y;
				list.push(temp);
			}
	
			if(tube[x-1][y]==1)
			{
				step temp;
				temp.x=x-1;
				temp.y=y;
				list.push(temp);
			}
			list.pop();
		}
		int ans=0;
		cout<<"Case "<<num<<":\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(tube2[i][j]>=100)
				{
					cout<<"0"<<" ";
				}
				else
				cout<<tube2[i][j]<" ";
			}
			cout<<"\n";
		}
	}
}
void bfs()
{
	
}
void bfs(int s)
{
	
}


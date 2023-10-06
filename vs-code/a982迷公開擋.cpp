#include<iostream>
#include<algorithm>
#include<fstream>
#include<queue> 
using namespace std;
struct step{
	int x;
	int y;
};

queue<step> list;
	char maze[100][100];
	int maze2[100][100]={0};
	int n;
int main()
{
	fstream file;
	file.open("°g®c.txt");
	file>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			file>>maze[i][j];
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<maze[i][j];
//		}
//		cout<<"\n";
//	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			maze2[i][j]=1000;
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<maze2[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
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
		//cout<<"size "<<list.size()<<endl;
		int x=list.front().x;
		int y=list.front().y;
		//cout<<x<<" "<<y<<endl;
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
//		else
//		{
//			cout<<"NORRR\n";
//			cout<<maze[x][y+1]<<" "<<(maze2[x][y+1]>maze2[x][y])<<endl;	
//		} 
//		
		if(maze[x][y-1]!='#'&&maze2[x][y-1]>maze2[x][y])
		{
			step temp;
			temp.x=x;
			temp.y=y-1;
			list.push(temp);
		}
//		else
//		{
//			cout<<"NOLLL\n";
//			cout<<maze[x][y-1]<<" "<<(maze2[x][y-1]>maze2[x][y])<<endl;	
//		} 
		if(maze[x+1][y]!='#'&&maze2[x+1][y]>maze2[x][y])
		{
			step temp;
			temp.x=x+1;
			temp.y=y;
			list.push(temp);
		}
//		else
//		{
//			cout<<"NODDD\n";
//			cout<<maze[x+1][y]<<" "<<(maze2[x+1][y]>maze2[x][y])<<endl;	
//		} 
		if(maze[x-1][y]!='#'&&maze2[x-1][y]>maze2[x][y])
		{
			step temp;
			temp.x=x-1;
			temp.y=y;
			list.push(temp);
		}
//		else
//		{
//			cout<<"NOUUU\n";
//			cout<<maze[x-1][y]<<" "<<(maze2[x-1][y]>maze2[x][y])<<endl;
//		} 
		list.pop();
//		
//		for(int i=0;i<n+2;i++)
//		{
//			for(int j=0;j<n+2;j++)
//			{
//				cout<<maze[i][j];
//			}
//			cout<<"\n";
//		}
//		for(int i=0;i<n+2;i++)
//		{
//			for(int j=0;j<n+2;j++)
//			{
//				if(maze2[i][j]>=1000)
//				{
//					
//				}
//				else if(maze2[i][j]>=100)
//				{
//					cout<<"0";
//				}
//				else if(maze2[i][j]>=10)
//				{
//					cout<<"00";	
//				}
//				else if(maze2[i][j]<10)
//				{
//					cout<<"000";
//				 } 
//				
//				cout<<maze2[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
	}
	if(list.empty())
	cout<<"No solution!"<<endl;
	else
	{
		cout<<maze2[n][n]<<endl;
	}
}


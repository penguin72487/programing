#include<iostream>
#include<deque>
#include<map>
using namespace std;
class spot{
public :	
	int x;
	int y;
	spot(int t,int tmp)
	{
		x=t;
		y=tmp;
	}
	bool cmp(spot val,spot val2) 
	{
		if(val.x==val2.x)
		{
			return(val.y>val2.y);
		}
		else
		{
			return (val.x,val2.x);
		}
	}
};
int main()
{
	//ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	n+=2;
	m+=2;
	int maze[n][m];
	fill(maze[0],maze[n-1]+m,0);
	deque<spot> list;
	map<spot,deque<spot>::iterator,spot.cmp> si_Map;
	int ans1=0,ans2=0,ans_Tol=0;
	for(int i=1;i<n-1;++i)
	{
		for(int j=1;j<m-1;++j)
		{
			cin>>maze[i][j];
			if(maze[i][j]==5)
			{
				spot tmp(i,j);
				list.push_back(tmp);
				si_Map[tmp]=list.end();
			}
			else if(maze[i][j])
			{
				++ans_Tol;
			}
		} 
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cout<<maze[i][j]<<" ";
		} 
		cout<<"\n";
	}
	int dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={-1,1,0,1,-1,0,1,-1};
	while(!list.empty())
	{
		int x=list.front().x;
		int y=list.front().y;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(maze[i][j]==5)
				{
					 
				}
			}
		}
		
		
		list.pop_front();
		
	}
	

}


#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
struct step{
	int x;
	int y;
};

queue<step> list;
char jizz[501][501];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false); 
	int n,m;
	cin>>n>>m;
	n^=m^=n^=m;
	char jizz[n][m];
	int ans=0,ans2=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>jizz[i][j];
		}
	}
	int x;
	int y;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(jizz[i][j]=='J')
			{
				int a=0;
				ans++;
				step temp;
				temp.x=i;
				temp.y=j;
				list.push(temp);
				while(list.empty()==0)
				{
			
					int x=list.front().x;
					int y=list.front().y;
					
					//cout<<x<<" "<<y<<endl; 
					//if(jizz[x][y]=='X')
					if(x<0||y<0||x>=n||y>=n||jizz[x][y]=='X')
					{
						jizz[x][y]='X';
						list.pop();
						continue;
					}
					jizz[x][y]='X';
					
					
					if(jizz[x][y+1]=='J')
					{
						step temp;
						temp.x=x;
						temp.y=y+1;
						list.push(temp);
					}
				
					if(jizz[x][y-1]=='J')
					{
						step temp;
						temp.x=x;
						temp.y=y-1;
						list.push(temp);
					}
			
					if(jizz[x+1][y]=='J')
					{
						step temp;
						temp.x=x+1;
						temp.y=y;
						list.push(temp);
					}
			
					if(jizz[x-1][y]=='J')
					{
						step temp;
						temp.x=x-1;
						temp.y=y;
						list.push(temp);
					}
					a++;
					list.pop();
				}
				ans2=max(a,ans2);
			}	
		}
	}
	cout<<ans<<" "<<ans2<<endl;
}


#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int step[10][10]={0};

int n,m;
struct loc{
	int x;
	int y;
}s[100];
int main()
{
	loc start;
	start.x=1;
	start.y=1;
	deque <loc> road;
	road.push_back(start);
	cin>>n>>m;
	char s[n+2][m+2];
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1)
				s[i][j]='#';
			else
				cin>>s[i][j];	
		}	
	}
	
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
				cout<<s[i][j];	
		}	
		cout<<"\n";
	}
	
		
} 


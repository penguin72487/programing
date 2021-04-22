#include<iostream>
using namespace std;
int n;
int tre[17];
int tol=0;
int avg;
bool can=0;
void bfs(int num,int Alice,int Bob,int Cindy);
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tre[i];
		tol+=tre[i];
	}
	if(tol%3!=0)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		avg=tol/3;
		bfs(0,0,0,0);
		if(can)
		{
		
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
	}
	
}
void bfs(int num,int Alice,int Bob,int Cindy)
{
	if(Alice>avg||Bob>avg||Cindy>avg)
	{
		return ;
	}
	if(num==n)
	{
		if(Alice==Bob&&Bob==Cindy)
		{
			can=1;
			return ;
		}
		else
		{
			return ;
		}
	}
	if(!can)
	{
		bfs(num+1,Alice+tre[num],Bob,Cindy);
	}
	if(!can)
	{
		bfs(num+1,Alice,Bob+tre[num],Cindy);
	}
	if(!can)
	{
		bfs(num+1,Alice,Bob,Cindy+tre[num]);
	}
	
}


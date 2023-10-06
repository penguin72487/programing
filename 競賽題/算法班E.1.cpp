#include<iostream>
#include<vector>
using namespace std;
void step(int x,int y,int type,int chess[],vector<int> decar);
int n,m;
int main()
{

	int k,type;
	int i,j;	
	cin>>n>>m>>k>>type;
	int chess[n*m]={0};
	vector <int> decar;//decar[K+][3]//decar(i*3+j)
	/* 
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>chess[i*m+j];
		}
	}
	*/
	//cout<<"«¢«¢\n"; 
	/*
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<chess[i*m+j]<<" ";
		}
		cout<<endl;
	}
	*/
	int x,y,t;
	while(k>0)
	{
		
		cin>>x>>y>>t;
		x--;
		y--;
		if(type=2)
		{
			t=2;
		}
		decar.push_back(x);
		decar.push_back(y);
		decar.push_back(t);
		step(x,y,t,chess,decar);
		k--;
	}
	int ans=0;
	  
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(chess[i*m+j]==0)
			{
				step(i,j,type,chess,decar);
				ans++;
			} 
			
		}
	} 
	
	cout<<ans<<endl;
	return 0;
}
void step(int x,int y,int type,int chess[],vector<int> decar)
{
	//cout<<"«¢«¢\n";
	int i,j;
	decar.push_back(x);
	decar.push_back(y);
	decar.push_back(type);
	for(i=0;i<n;i++)
	{
		//cout<<"«¢«¢NNN\n";
		for(j=0;j<m;j++)
		{
		//	cout<<"«¢«¢MMM\n";
			if(i-j==x-y||i+j==x+y||i==x||j==y)
			{
				chess[i*m+j]=1;
			}
			if((i-x)*(i-x)+(j-y)*(j-y)==5&&type==2)
			{
				chess[i*m+j]=1;
			}
		}
	}
	chess[x*m+y]=2;
	//cout<<"«¢«¢\n";
	/*
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<chess[i*m+j]<<" ";
		}
		cout<<endl;
	}
	*/
}


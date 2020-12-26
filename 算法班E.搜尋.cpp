#include<iostream>
using namespace std;
void step(int x,int y,int type,int chess[]);
int n,m;
int main()
{

	int k,type;
	int i,j;	
	
while(cin>>n>>m>>k>>type)
{
			int chess[n*m]={0};
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
		if(type==2)
		{
			t=2;
		}
		step(x,y,t,chess);
		k--;
	}
	int ans=0;
	int chess2[n*m]={0};
	
	cout<<"r>>c·j´M\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			chess2[i*m+j]=chess[i*m+j];
		}
	}
	for(i=0;i<n;i++)  //r>>c·j´M 
	{
		for(j=0;j<m;j++)
		{
			if(chess[i*m+j]==0)
			{
				step(i,j,type,chess2);
				ans++;
			} 
			
		}
	} 
	cout<<"ans: "<<ans<<endl;
	
	
	cout<<"c>>r·j´M \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			chess2[i*m+j]=chess[i*m+j];
		}
	}
	for(i=0;i<m;i++)//c>>r·j´M 
	{
		for(j=0;j<n;j++)
		{
			if(chess[j*n+i]==0)
			{
				step(j,i,type,chess2);
				ans++;
			} 
			
		}
	} 
	cout<<"ans: "<<ans<<endl;
	
	
	
	
	
	
	cout<<"-c>>r·j´M \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			chess2[i*m+j]=chess[i*m+j];
		}
	}
	for(i=n-1;i>=0;i--)//-c>>r·j´M 
	{
		for(j=0;j<m;j++)
		{
			if(chess[i*m+j]==0)
			{
				step(i,j,type,chess2);
				ans++;
			} 
			
		}
	} 
	cout<<"ans: "<<ans<<endl;
	
	
	
	
	
	
	
	cout<<"-r>>c·j´M \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			chess2[i*m+j]=chess[i*m+j];
		}
	}
	for(i=n-1;i>=0;i--)//-r>>c·j´M 
	{
		for(j=0;j<m;j++)
		{
			if(chess[j*n+i]==0)
			{
				step(j,i,type,chess2);
				ans++;
			} 
			
		}
	} 
	cout<<"ans: "<<ans<<endl;
	
	
	cout<<"-c>>-r·j´M \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			chess2[i*m+j]=chess[i*m+j];
		}
	}
	for(i=m-1;i>=0;i--)//-c>>-r·j´M 
	{
		for(j=n-1;j>=0;j--)
		{
			if(chess[i*m+j]==0)
			{
				step(i,j,type,chess2);
				ans++;
			} 
			
		}
	} 
	cout<<"ans: "<<ans<<endl;
	
	
	
	
	
	cout<<"-r>>-c·j´M\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			chess2[i*m+j]=chess[i*m+j];
		}
	}
	for(i=m-1;i>=0;i--)//-r>>-c·j´M 
	{
		for(j=n-1;j>=0;j--)
		{
			if(chess[j*n+i]==0)
			{
				step(j,i,type,chess2);
				ans++;
			} 
			
		}
	} 
	
	
	cout<<"ans: "<<ans<<endl;
	
}
return 0;
}
void step(int x,int y,int type,int chess[])
{
	cout<<"«¢«¢\n";
	int i,j;
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
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<chess[i*m+j]<<" ";
		}
		cout<<endl;
	}
	
	
}


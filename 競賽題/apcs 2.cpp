#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int r,c,k,m;
	cin>>r>>c>>k>>m;
	int l[r+2][c+2]={0};
	int i,j;
	for(i=0;i<r+2;i++)
	{
		for(j=0;j<c+2;j++)
		{
			if (i==0||i==r+1||j==0||j==c+1)
			l[i][j]=-1;
			else
			cin>>l[i][j];
	}
} 
/*
	for(i=0;i<r+2;i++)
	{
		for(j=0;j<c+2;j++)
		{
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	*/ 
	for(int day=0;day<m;day++) 
	{
			int o[r+2][c+2]={0};
			for(i=1;i<r+1;i++)
	{ 
		for(j=1;j<c+1;j++)
	{
	if(l[i][j]>=k)
	{
		if(l[i+1][j]>=0)
		{
			o[i+1][j]+=l[i][j]/k;
			o[i][j]-=l[i][j]/k;
		}
			if(l[i-1][j]>=0)
		{
			o[i-1][j]+=l[i][j]/k;
			o[i][j]-=l[i][j]/k;
		}
			if(l[i][j+1]>=0)
		{
			o[i][j+1]+=l[i][j]/k;
			o[i][j]-=l[i][j]/k;
		}
			if(l[i][j-1]>=0)
		{
			o[i][j-1]+=l[i][j]/k;
			o[i][j]-=l[i][j]/k;
		}
			for(i=1;i<r+1;i++)
	{
		for(j=1;j<c+1;j++)
	{
		l[i][j]+=o[i][j];
	}
	}
}
}
}

	}
	int int_max=0,int_min=2147483647;
		 for(i=1;i<r+1;i++)
	{
		for(j=1;j<c+1;j++)
		{
			if(l[i][j]>=0)
			{
			int_max=max(int_max,l[i][j]);
			int_min=min(int_min,l[i][j]);
			} 
		}
	}
	cout<<int_min<<endl<<int_max<<endl;
}



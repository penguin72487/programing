#include<iostream>
using namespace std;
int main()
{
	int x,y,i,j,n;
	cin>>x>>y;
	char L[y+2][x+2];
	for(i=0;i<y+2;i++)
	{
		for(j=0;j<x+2;j++)
		{
			if (i==0||i==y+1||j==0||j==x+1)
			L[i][j]='*';
			else
			{ 
			cin>>L[i][j];
			if(L[i][j]!='*')
			n+=L[i][j]-'0';
		}
		}
		} 
	for(i=1;i<y+2;i++)
	{
		for(j=1;j<x+2;j++)
		{
			if (L[i][j]!='*'&&L[i-1][j]==L[i+1][j]&&L[i+1][j]==L[i][j-1]&&L[i][j-1]==L[i][j+1]&&L[i][j+1]=='*')
				n-=(L[i][j]-'0');
		}
	} 
	cout<<n<<endl;
}

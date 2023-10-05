#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int l[4][2];
	int i,j,ans=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			cin>>l[i][j];
		}
	}
	l[3][0]=l[0][0];
	l[3][1]=l[0][1];
	for(i=0;i<3;i++)
	{
		ans+=l[i][0]*l[i+1][1];
		ans-=l[i][1]*l[i+1][0];
	}
	cout<<abs(ans)<<endl;
}


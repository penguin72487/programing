#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=i;j<4;j++)
		{
			for(k=0;k<5;k++)
			{
				ans++;
				//cout<<ans<<endl;
			}
		}
	}
	cout<<ans<<endl;
}

#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	int r=n+1,c=n+1;
	unsigned short l[r*c]={0},i,j;
	for(i=1;i<n;i++)
	{
		cin>>l[i];
	}
	for(i=1;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			l[r*i+j]=l[(r-1)*i+j];
			if(l[r*i+j]=l[i]&&l[i]<l[i-1])
			l[i]^=l[i-1]^=l[i]^=l[i-1];
		}
	}
	int int_r,int_c,int_n;
	cin>>int_n;
	for(i=0;i<int_n;i++)
	{
		cin>>int_r>>int_c;
		cout<<l[int_r*r+int_c]<<endl;
	}
	
}

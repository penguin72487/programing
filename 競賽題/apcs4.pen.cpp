#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n;
	auto a=0;
	ios::sync_with_stdio(false);
	cin>>n;
	int l[n+1]={0},h=0,i,j;
	for(i=0;i<2*n;i++)
	{
		ios::sync_with_stdio(false);
		cin>>a;
		if(a>0&&a<CHAR_MAX)
		unsigned char a;
		else if(a>CHAR_MAX&&a<USHRT_MAX)
		unsigned short a;
		else if (a>USHRT_MAX&&a<ULONG_MAX)
		unsigned long a;
		else if (a>ULONG_MAX&&a<ULONG_LONG_MAX)
		unsigned long long a;
		l[a]++;
		for(j=a+1;j<=n;j++)
		{
			if(l[j]==1)
			h++;
		}
	}
	printf("%d",h);
}

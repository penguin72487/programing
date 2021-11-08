#include<iostream>
using namespace std;
int f(int n)
{
	int f[]={0,1};
		for(int i=0;i<n;i++)
		{
			
			int tmp=f[1];
			f[1]=(f[1]+f[0])%(1000000000+7);
			f[0]=tmp;
		}
		return f[0];
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n&&n)
	{
		cout<<(f(n-1)+f(n+1))%(1000000000+7)<<endl;
	}
}


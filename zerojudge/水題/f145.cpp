#include <stdio.h>
#include <math.h>
unsigned long long f(int n);
unsigned long long g(int n);
unsigned long long h(int n);
unsigned long long dp_f[10000];
unsigned long long dp_g[10000];
unsigned long long dp_h[10000];
int main( )
{
    int n, i,j;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("%llu\n",g(n));
	}
	
	
	
}
unsigned long long f(int n)
{
	unsigned long long ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=h(i);
	}
	
	return ans;
	
}
unsigned long long g(int n)
{
	unsigned long long ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=f(i);
	}
	
	return ans;
	
}
unsigned long long h(int n)
{
	if(h[n]!=0)
	return h[n];
	double sum=0;
	for(int i=1; i<=n; i++)
	{
		sum += log10((double)(i));
	}

    return (int)sum+1;
}

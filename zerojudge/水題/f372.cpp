#include<stdio.h>
int l[5004];
int f(int a,int n)
{

	if(n==0)
	return 1;
	if(n==1)
	return a;
	if(l[n]!=0)
	return l[n];
	return l[n]=(f(a,n-1)*a)%10007 ;
}
int main()
{
	int a=3,n;

while (scanf("%d",&n)!=EOF)
{

printf("%d\n",f(a,n % 5003));
}
} 

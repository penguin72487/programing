#include<stdio.h>
int main()
{
	unsigned long long s,d;
	while(scanf("%llu%llu",&s,&d)!=EOF)
	{
	if(d==0)
		printf("Go Kevin!!\n");
	else
	{
	int n=1;
	while(((2+(n-1)*d)*n)/2<s)
	{
		
		n++;
	}

	
	if(((2+(n-1)*d)*n)/2==s)
		printf("Go Kevin!!\n");
	else
		printf("No Stop!!\n");
	}
}
}

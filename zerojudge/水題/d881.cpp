#include<stdio.h>
int main ()
{
	int d,h=0;
	while(scanf("%d",&d)!=EOF)
	{
	int i;
	for(i=1;i<=50;i++)
	h+=h+d;
	printf("%d",h);
}
 } 

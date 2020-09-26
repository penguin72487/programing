#include<stdio.h>
int main ()
{
	int a,b;
	scanf("%d%d",&a,&b);
	a^=b^=a^=b;
	printf("%d %d\n",a,b);
}

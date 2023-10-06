#include<stdio.h>
int main()
{
	int b=0,i,j;
	char n;
	scanf("%c",&n);
	unsigned short a;
	for (j=0;j<n-'0';j++)
	{
		scanf("%hu",&a);
		b=0;
	for(i=a-1;i>0;i--)
	{
		if(a%i==0)
		b=b+i;
		
		
	}
	if (b==1)
	printf("Y\n");
	else 
	printf("N\n");
}
}

#include<stdio.h>
int main()
{
	int a=1,b=0,i;
	//while (scanf("%d",&a)!=EOF)
	while(a<=2147483647)
	{
		b=0;
	for(i=a-1;i>0;i--)
	{
		if(a%i==0)
		b=b+i;
		
		
	}
	if(b==1)
	printf("%d ",a);
/*	if (b==1)
	printf("質數\n");
	else 
	printf("非質數\n");
	*/
	a++;
}
}

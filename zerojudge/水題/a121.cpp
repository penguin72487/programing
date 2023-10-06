#include<stdio.h>
int main()
{
	int a=1,c,i;
	while (scanf("%d%d",&a,&c)!=EOF)
	{
		int j,h=0;
	for(j=a;j<c+1;j++)
	{
		int b=0;
	for(i=j-1;i>0;i--)
	{
		if(j%i==0)
		b=b+i;
		
		
	}
	if(b==1)
	h++;

/*	if (b==1)
	printf("質數\n");
	else 
	printf("非質數\n");
	*/
}
	printf("%d\n",h);
}
}

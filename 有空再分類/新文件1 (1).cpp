#include<stdio.h>
int main()
{
	int a,n=1,i,j;
	while(scanf("%d",&a)){
		if(a<0)
		break;
		j++;
		n=0;
		if(a<2)
		printf("Case %d: 0\n",j);
		else{
		for(i=0;n<a;i++)
		n=n*2;
		printf("Case %d: %d\n",j,i);
	}
	}
}

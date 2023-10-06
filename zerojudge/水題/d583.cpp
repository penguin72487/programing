#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			printf("%d ",i+1);
		}	
		printf("\n");
	}

}

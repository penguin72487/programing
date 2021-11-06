#include <stdio.h>
int main ()
{
	int a[10000],b,c=0,j,i=0,n;
	for (scanf("%d", &n);i<n;i++)
	scanf(" %d", &a[i]);
	scanf("%d", &b);
	
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			if(a[j]-a[i]==b)
				
				printf("Yes\n%d %d\n",i,j );
				c=c+(a[j]-a[i]==b);
		}
	}
	if(c==0)
	printf("No\n");
}

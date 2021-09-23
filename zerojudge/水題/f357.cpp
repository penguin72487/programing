#include <stdio.h>
#include <math.h>

int main( )
{
    int n, i;
    
while(scanf("%d",&n)!=EOF)
{
	double sum=0;
    for(i=1; i<=n; i++)
        sum += log10((double)(i));
    printf("%d\n", (int)sum+1);
}
}

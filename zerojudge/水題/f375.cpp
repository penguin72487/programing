#include <stdio.h>
#include <math.h>

int main( )
{
    
for(int n=1;n<=100;n++)
{
	double sum=0;
    for(int i=1; i<=n; i++)
        sum += log10((double)(i));
    printf("%d\n", (int)sum+1);
}
}

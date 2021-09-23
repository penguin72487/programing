#include<stdio.h>
int main()
{
int i,n;
scanf("%d",&n);

int* loc =l[n];
for(i=0;i<n;i++)
scanf("%d",loc+i);
for(i=0;i<n;i++)
printf("%d ",*(loc+n-i-1));

}

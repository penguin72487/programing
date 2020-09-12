#include<stdio.h>
int main()
{
int a,n=0,i,m;
while(scanf("%d%d",&a,&m )!=EOF)
{
for(i=0;n<=m;i++)
{
n=n+a+i;
printf("%d\n",n);
}
printf("%d\n",i);
}
} 

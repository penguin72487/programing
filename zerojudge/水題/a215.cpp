#include<stdio.h>
int main()
{
int a,n=0,i,m;
while(scanf("%d%d",&a,&m )!=EOF)
{
n=0;
for(i=0;n<=m;i++)
n=n+a+i;
if(i==0)
   i++;
printf("%d\n",i);
}
}

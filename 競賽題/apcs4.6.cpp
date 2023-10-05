#include<stdio.h>
int main()
{
 int n;
 auto a=0;
 scanf("%d",&n);
 int l[n+1]={0},h=0,i,j;
 for(i=0;i<2*n;i++)
 {
  scanf("%d",&a);
  l[a]++;
  for(j=a+1;j<=n;j++)
  {
   if(l[j]==1)
   h++;
  }
 }
 printf("%d\n",h);
}

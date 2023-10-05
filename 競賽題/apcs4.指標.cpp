#include<stdio.h>
int main()
{
 int n,a;
 int* loc_n= &n;
 scanf("%d",loc_n);
 int l[n+1]={0},h=0,i,j;
 int* loc= l,loc_h=h,loc_i=i,loc_j=j,loc_a=a;

 for(loc_i=0;loc_i<2**loc_n;loc_i=loc_i+1)
 {
  scanf("%d",loc_a);
  *(loc+a)=*(loc+a)+1;
   //printf("%d",*(loc+a));
    for(loc_j=loc_a+1;loc_j<=loc_n;j++)
  {
   if(l[j]==1)
   h++;
  }
 }
 printf("%d\n",h);
}

#include<stdio.h>
#include<algorithm>
int main()
{
int i,n,int_max=-1,int_min=101;
scanf("%d",&n);
int *loc = new int[n];
for(i=0;i<n;i++)
{
scanf("%d",loc+i);
if(*(loc+i)<60)
int_max=std::max(int_max,*(loc+i));
else
int_min=std::min(int_min,*(loc+i));
}
std::sort(loc,loc+n);
for(i=0;i<n;i++)
printf("%d ",*(loc+i));
printf("\n");
if(int_max==-1)
printf("best case\n");
else
printf("%d\n",int_max);
if(int_min==101)
printf("worst case\n");
else
printf("%d\n",int_min);
delete [] loc;
} 

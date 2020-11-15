#include<stdio.h>
int main()
{
int i,n;
scanf("%d",&n);
int* val = &n;
int l[n];
int *loc ;
for(loc=l;loc<l+*val;loc++)
scanf("%d",loc);
for(loc=l+*val-1;loc>=l;loc--)
printf("%d ",*(loc));

}

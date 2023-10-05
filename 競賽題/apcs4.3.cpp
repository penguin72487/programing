#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
 int n,a;
 scanf("%d",&n);
 int h=0,i,j;
 string l;
 for(i=0;i<2*n;i++)
 {
  scanf("%d",&a);
 h+=count(l.find(a,i),l.find(a,i),l[i]<a);
 }
 printf("%d\n",h);
}

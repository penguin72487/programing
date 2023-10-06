#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:1996)

int main() {
 int n, a, b, c, d, e;
 scanf("%d", &n);
 for (int i = 1; i <= n; i++) {
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  int w1 = d - e, w2 = d + e;
  if (((b - c) * a >= w1 && (b - c) * a <= w2) && ((b + c) * a >= w1 && (b + c) * a <= w2))
   printf("yes\n");
  else
   printf("No\n");
 }
 return 0;
}
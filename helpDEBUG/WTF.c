#include <stdio.h>
int main()
{
    int x[10];
    for(int i=0; i<10; i++)
    {
        x[i] = i+1;
    }

    printf("x address =%p\n", x);
    printf("&x[0] address =%p\n", &x[0]);
    printf("x[3]=%n\n", &x[3]);
    printf("%d\n", x[3]);
}
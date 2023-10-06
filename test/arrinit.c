#include<stdio.h>
int main()
{
    int i_Sum = 0;
    int a[4] = {1, 2, 3};
    for (int i = 1; i < 4;++i)
    {
        i_Sum += a[i];
    }
    printf("%d",i_Sum);
}
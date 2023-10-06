#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 

int main()
{
    int hh,mm,ss;
    int sec;
    //char cmd[20]="shutdown -s -t";
    //char t[5];
    scanf("%d %d %d",&hh,&mm,&ss);
    sec=hh*6060+mm*60+ss;
    system('shutdown -s-t sec');
    system("pause");
    return 0;
}
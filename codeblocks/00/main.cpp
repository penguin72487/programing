#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char cmd[20]="shutdown-s-t";
    char t[5]="0";
    int time;
    int hh,mm,ss;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    time=hh*60*60+mm*60+ss;
    itoa(time,t,5);
    system(strcat(cmd,t));
    system("pause");
    return 0;
}

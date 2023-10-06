#include <iostream>
#include <cmath>
int main()
{
    int val;

while(scanf("%d",&val)!=EOF)
{
        int a;
    bool out=0;
    double ans;
    int i;
    for(i=1;i<=val/2+1;i++)
    {
        int c=(a-a*a)-val*2;
        //if(sqrt(1-4*c)<0)
          //  continue;

        a=i;
        ans=((-1)+sqrt(1-4*c))/(2);
        printf("i a-1 ans %d %d-%g\n",i,a-1,ans);
/*
        if(ans-(int)ans== 0&&(a-1)>0)
        {
            out=1;
            printf("%d-%g\n",a-1,ans);
           continue;
        }
*/
        if(ans-(a-1)==1)
            break;
    }
    if(out==0)
       printf("No Solution...\n");



}

return 0;

}

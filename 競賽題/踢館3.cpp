#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,a,b,w,i,n;
	for(scanf("%d" , &t);t>0;t--)
	{
	scanf("%d%d%d", &a,&b,&w);
    if((a>b&&w==2)||(b>a&&w==1)||(max(a,b)<22))
    printf("NO\n");
    else if(abs(abs(a-b)-12)>=11) 
    printf("NO\n");
    else if(min(a,b)<=18)
    printf("YES\n");
    else if (abs((max(a,b)-11)-b)>2)
    printf("NO\n");
    else
    printf("YES\n");
    qq
}
}

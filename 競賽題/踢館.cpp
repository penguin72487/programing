#include <stdio.h>
int main ()
{
	int a;
	
	while (scanf("%d", &a)){
	
	if((a+5)>7)
	printf("%d\n", (a+5)%7);
	else 
	printf("%d\n", a+5);
	
}
}

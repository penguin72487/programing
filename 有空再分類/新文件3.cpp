#include <stdio.h>
#include <string.h>

int main ()
{
	int d;
	string a,b,c;
	scanf("%s%s%s",&a,&b,&c);
    a = a.replace(a.find(b),b.length(),c);
    printf("%s\n", a.c_str());
    d = abs(a+b+c);



}

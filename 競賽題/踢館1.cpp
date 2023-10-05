#include <stdio.h>
#include <string.h>
int main ()
{
	std::string a,b,c;
	scanf("%s%s%s",&a,&b,&c);
    a = a.replace(a.find(b),b.length(),c);
    printf("%s\n", a.c_str());
    



}

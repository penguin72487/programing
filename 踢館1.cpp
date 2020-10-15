#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	string a,b,c;
	scanf("%s%s%s",&a,&b,&c);
    a = a.replace(a.find(b),b.length(),c);
    printf("%s\n", a.c_str());
    



}

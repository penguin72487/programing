#include<stdio.h>
int  main()
{
setvbuf (stdout, NULL, _IOFBF, 32768);
puts("313 472\n");
return 0;
}

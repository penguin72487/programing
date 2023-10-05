#include<iostream>
int main()
{
	int a,b=0,i;
	while (std::cin>>a&&a!=0)
	{
		b=0;
	for(i=a-1;i>0;i--)
	{
		if(a%i==0)
		b+=i;
	}
	if(a==b)
	printf("=%d\n", a);
	else
	{
		//printf("b %d\n", b);
		int c=0;
			for(i=b-1;i>0;i--)
	{
		if(b%i==0)
		c+=i;
	}
		if(a==c)
		printf("%d\n",b);
		else
		printf("0\n");
		
	}

}
}

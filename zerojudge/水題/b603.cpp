#include<iostream>
#include<algorithm>
using namespace std;
int o_al(int a,int b)
{
	if(a%b==0)
	return b;
	else
	return o_al(b,a%b);
}
int main()
{
	int h,k,x,y;
	while(cin>>h>>k>>x>>y)
	{
		int r = abs(x-h);
		int a= ((y-k)/(x-h)*(x-h));
		int b= ((-2)*a*h);
		int c= (a*h*h+k*r);
		int g=o_al(o_al(a,b),o_al(c,r));
		printf("%dy = %dx^2 + %dx + %d\n",r,a/g,b/g,c/g);
	
		
	}
	
	
}

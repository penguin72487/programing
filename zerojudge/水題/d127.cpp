#include<iostream>
int main()
{
long long int a,b,n;
	while(std::cin>>n&&n!=-1)
	{
a= n/4;

b= n-2*a;

b=b/2;
std::cout<<a*b<<std::endl;
}
}

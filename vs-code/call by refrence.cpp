#include<iostream>
using namespace std;
void f(int *n)
{
	(*n)++;
}
int main()
{
	int a=10;
	f(&a);
	cout<<a<<endl;
}


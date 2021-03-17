#include<iostream>
using namespace std;
int a[536698431];
int main()
{
	int *p=new int [2147483648];
	int *r=new int [2147483648];
	delete [] p;
	delete [] r;
	return 0;
}


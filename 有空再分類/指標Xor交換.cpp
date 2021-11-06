#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int *it=&a;
	int *jt=&b;
	cout<<it<<endl;
	cout<<jt<<endl;
	cout<<it<<endl;
	cout<<it-jt<<endl;
}


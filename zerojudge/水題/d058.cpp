#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n--;
	cout<<(n!=-1)*(n/abs(n))<<endl;
 } 

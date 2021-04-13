#include<iostream>
using namespace std;
int main()
{
	//1＋（-2147483647）*1 - 5
	int a=1,b=-2147483647,c=1,d=1000000,e=5;
	cout<<"�즡"<<a+b*c-e <<endl; 
 	cout<<"(A)"<<(((a+b)*c)-e)<<endl;
	cout<<"(B)"<<((a+b)*(c-e))<<endl;
	cout<<"(C)"<<((a+(b*c))-e)<<endl;
	cout<<"(D)"<<(a+((b*c)-e))<<endl;
} 

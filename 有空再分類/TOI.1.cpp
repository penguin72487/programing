#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int day=n-n/2000*200,chi=n-n/1000*100;
	if(day<=chi)
	cout<<day<<" 0"<<endl;
	else
	cout<<chi<<" 1"<<endl;
	

	
}

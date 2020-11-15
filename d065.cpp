#include<iostream>
 #include<algorithm> 
using namespace std;
int main()
{
	int n=3;
	int i,a,int_max;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		int_max=max(int_max,a);
	}
	cout<<int_max<<endl;
}

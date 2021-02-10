#include<iostream>
using namespace std;
int main()
{
	int n,k,w;
	cin>>n>>k>>w;
	int num=n;
	while(num>=k)
	{
		num-=k;
		num+=w;
		n+=w;
		
	}
	cout<<n<<endl;
}

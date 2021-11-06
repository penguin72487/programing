#include <iostream>

using namespace std;

int main()
{
    int a=0,b=0,i=0,n[51];
    float avg;
    for(cin>>n;i<n;i++)
    {
    	cin>>n[i];
    	a=n[i]+a;
	}
	avg=a/i;
	for(i=0;i<n;i++)
	{
	b=b+n[i]-avg;
	}
	cout<<"The minimum number of moves is "<<b<<".";
    return 0;
}

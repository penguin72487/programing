#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,j;
 
for(cin>>i;i>0;i--)
{
	int a,b=0,l=0;
	for(cin>>j;j>0;j--)
	{
		cin>>a;
		if (a>=b)
		{
			b=a;
			++l;
		}
	}
	cout<<l<<endl;
}
} 

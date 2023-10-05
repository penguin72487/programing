#include <iostream>
using namespace std;

int main () 
{
	int n;
	cin>>n;
	int a,b;
	int x=0,y=0;
	int i;
	for(i=0;i<n;i++)
	{
			cin>>a>>b;
			if(a==0)
			y+=b;
			else if(a==1)
			x+=b;
			else if(a==2)
			y-=b;
			else
			x-=b;
	}
	cout<<x<<" "<<y<<endl;
}

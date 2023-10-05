#include <iostream>
# include <math.h> 
using namespace std;
int main()
{
float a,b,c;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a>>b>>c;
	float ace=sqrt(b*b-4*a*c);
	int result=ace;
	if (ace == result)
	cout <<"Yes"<<endl;
	else 
	cout <<"No"<<endl;	
}
return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
	 long double  l[3];
	int n;
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
	int j;
	for(j=0;j<3;j++)
	cin>>l[j];
	sort(l,l+3);

	if(l[0]*l[0]+l[1]*l[1]==l[2]*l[2])
		cout<<"right triangle"<<endl;
	else if(l[0]*l[0]+l[1]*l[1]<l[2]*l[2])
		cout<<"obtuse triangle"<<endl;
	else if(l[0]*l[0]+l[1]*l[1]>l[2]*l[2])
		cout<<"acute triangle"<<endl;
}
	
}

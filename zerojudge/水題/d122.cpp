#include<iostream>
using namespace std;

int main()
{
unsigned long a;

while (cin>>a&&a!=-1)
{
int i=0;
while(a/5!=0)
{
	i+=a/5;
	a/=5;

}
cout<<i<<endl;


}
}

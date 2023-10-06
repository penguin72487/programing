#include <iostream>
#include <map>
#include<climits>
using namespace std;
struct penguin
{
	map<int,unsigned char> uc;
	map<int,unsigned short> us;
	map<int,unsigned long> ul;
	map<int,unsigned long long> ull;
};
penguin l;
	int i;
	int* loc=l;
auto pen(auto a)
{
		if(a>0&&a<CHAR_MAX)
		l.uc[i]=a;
		else if(a>CHAR_MAX&&a<USHRT_MAX)
		l.us[i]=a;
		else if (a>USHRT_MAX&&a<ULONG_MAX)
		l.ul[i]=a;
		else if (a>ULONG_MAX&&a<ULONG_LONG_MAX)
		l.ull[i]=a; 
	
}
int main()
{

	auto a=0;
	int n;

	cin>>n;//3
	for( i= 0;i<n;i++)
	{
	cin>>a;         //1 2100000000 999000000000000
	pen(a);
	}
	
}

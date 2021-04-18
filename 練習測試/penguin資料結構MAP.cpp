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
	cin>>n;
	for( i= 0;i<n;i++)
	{
	cin>>a;
	pen(a);
	}
	/*
	for(i= 0;i<n;i++)
	{
		cout<<"儲存所用記憶體大小: "<<sizeof(i->second)<<"數值為: "<<<map[i] <endl; 
	}
	*/
	for (auto it = 0; it != n; it++) {
        cout<<l<<" "<<l<<endl;
    }
	
} 

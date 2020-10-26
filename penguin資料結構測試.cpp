#include<iostream>
#include<climits>
#include<vector>
using namespace std;
struct penguin
{
	vector<int> loc;
	vector<unsigned char> uc;
	vector<unsigned short> us;
	vector<unsigned long> ul;
	vector<unsigned long long> ull;
};
penguin l;
int pen(auto a)
{
		l.loc.push_back(a);
		if(a>0&&a<CHAR_MAX)
		l.uc.push_back(a);
		else if(a>CHAR_MAX&&a<USHRT_MAX)
		l.us.push_back(a);
		else if (a>USHRT_MAX&&a<ULONG_MAX)
		l.ul.push_back(a);
		else if (a>ULONG_MAX&&a<ULONG_LONG_MAX)
		l.ull.push_back(a);
}
int main()
{
	auto a=0;
	int n,i;
	cin>>n;
	for(i=0;i<2*n;i++)
	{
		cin>>a;
		pen(a);
		auto* loc_v = l;
	}
	
}

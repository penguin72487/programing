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
	int n,i,h=0;
	int k[n+1]={0},j;
	cin>>n;
	auto a=0;
		for(i=0;i<2*n;i++)
	{
		cin>>a;
		l.loc.push_back(i);
		k[a]++;
		pen(a);		
		for(j=a+1;j<=n;j++)
		{
			
			if(k[j]==1)
			h++;
		}
	} 
		cout<<h<<endl;
	
	
	}

#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class node{
public:
	bool trace =1;
	vector <int> list;
};
void reset(node* tmp,int n);
int main()
{
	int n,m;
	cin>>n>>m;
	node course[n];
	for(int i=0;i<m;++i)
	{
		int tmp,tmp2;
		cin>>tmp>>tmp2;
		course[tmp].list.push_back(tmp);
	}
	deque <node> list;
	
	
	

}
void reset(node* tmp,int n)
{
	for(int i=0;i<n;++i)
	{
		tmp->trace=1;
		++tmp;
	}
}


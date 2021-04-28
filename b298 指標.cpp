#include<iostream>
#include<queue>
#include<vector>
using std::cin;
struct adj{
	std::vector<adj*> list;
	bool TUIHU=0;
};
int main()
{
	cin.tie(0);
	std::cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	int n,m,l,q;
	std::cin>>n>>m>>l>>q;
	std::queue<adj*> a;
	adj factory[n+1];
	for(int i=0;i<m;i++)
	{
		int tmp,tmp2;
		cin>>tmp>>tmp2;
		factory[tmp].list.push_back(&factory[tmp2]);
	}
	for(int i=0;i<l;i++)
	{
		int bad;
		cin>>bad;
		a.push(&factory[bad]);
		factory[bad].TUIHU=1;
	}	
	while(!a.empty())
	{
		adj* tmp=a.front();
		for(auto it=tmp->list.begin();it!=tmp->list.end();it++)
		{
			
			if((*it)->TUIHU==0)
			{
				a.push(*it);
				(*it)->TUIHU=1;
			}
		}
		a.pop();
	}
	for(int i=0;i<q;i++)
	{
		int qu;
		cin>>qu;
		if(factory[qu].TUIHU==1)
		{
			std::cout<<"TUIHUOOOOOO\n";
		}
		else
		{
			std::cout<<"YA~~\n";
		}
	}
}

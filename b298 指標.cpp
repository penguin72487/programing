#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct adj{
	vector<adj*> list;
	bool TUIHU=0;
};
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m,l,q;
	cin>>n>>m>>l>>q;
	queue<adj*> a;
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
	/*
	for(int i=0;i<n;i++)
	{
		for(auto it=Adj_list[i].begin();it!=Adj_list[i].end();it++)
		{
			cout<<*it<<endl;
		}
		cout<<endl;
	} 
*/		
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
			cout<<"TUIHUOOOOOO"<<endl;
		}
		else
		{
			cout<<"YA~~"<<endl;
		}
	}
}

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m,l,q;
	cin>>n>>m>>l>>q;
	queue<int> a;
	bool TUIHU[n+1]={0};
	vector<int> Adj_list[n+1];
	for(int i=0;i<m;i++)
	{
		int tmp,tmp2;
		cin>>tmp>>tmp2;
		Adj_list[tmp].push_back(tmp2);
	}
	int bad[l];
	for(int i=0;i<l;i++)
	{
		cin>>bad[i];
		a.push(bad[i]);
		TUIHU[bad[i]]=1;
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
		int tmp=a.front();
		for(auto it=Adj_list[tmp].begin();it!=Adj_list[tmp].end();it++)
		{
			//cout<<*it<<endl;
			if(TUIHU[*it]==0)
			{
				a.push(*it);
				TUIHU[*it]=1;
			}
		}
		a.pop();
	}
	for(int i=0;i<q;i++)
	{
		int qu;
		cin>>qu;
		if(TUIHU[qu]==1)
		{
			cout<<"TUIHUOOOOOO"<<endl;
		}
		else
		{
			cout<<"YA~~"<<endl;
		}
	}
}

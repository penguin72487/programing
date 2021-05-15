#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct adj{
	int val;
	vector<adj> list;
	bool pass=0;
};
bool out=0;
int main()
{
	
	int n,m;
	while(cin>>n>>m)
	{
		adj city[n+1];
		for(int i=0;i<=n;i++)
		{
			city[i].val=i;
		} 
		for(int i=0;i<m;i++)
		{
			int tmp,tmp2;
			cin>>tmp>>tmp2;
			city[tmp].list.push_back(city[tmp2]);
		}
		int op,ed;
		cin>>op>>ed;
		queue<adj> a;
		a.push(city[op]);
		city[op].pass=1;
		while(!a.empty())
		{
			adj tmp=a.front();
			for(auto it=tmp.list.begin();it!=tmp.list.end();it++)
			{
				
				if(it->val!=ed&&it->pass==0)
				{
					a.push(*it);
					it->pass=1;
				}
				else
				{
					out=1;
					break;
				}
			}
			a.pop();
		}
		if(out)
		{
			cout<<"Yes!!!"<<endl;
		}
		else
		{
			cout<<"No!!!"<<endl;
		}	
	}
	
}


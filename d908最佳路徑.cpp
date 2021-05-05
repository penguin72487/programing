#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct vec{
	int val;
	char ed;
};
struct node{
	char op;
	vector<vec> list;
	
};
node a[26];
int dfs(node a);
int main()
{
	int n;
	char op;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>op>>n;
	op-='A';
	
	for(int i=0;i<n;i++)
	{
		char op,ed;
		int val;
		cin>>op>>ed>>val;
		op-='A';
		ed-='A';
		vec tmp;
		tmp.val=val;
		tmp.ed=ed;
		a[op].list.push_back(tmp);
	}
	cout<<dfs(a[op])<<endl;
}
int dfs(node tmp)
{
	cout<<char(tmp.op+'A')<<endl;
	if(tmp.list.empty())	
	{
		return 0;	
	}
	
	int ans=0;
	for(auto it=tmp.list.begin();it!=tmp.list.end();it++)
	{
		ans=max(dfs(a[it->ed]),ans);
	}
	return ans;
}


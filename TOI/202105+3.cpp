#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	int list[n];
	for(int i=0;i<n;i++)
	{
		cin>>list[i];
	}
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		
		for(int j=i;j<n;j++)
		{ 
			int tmp=0;
			for(int k=j;k<n;k++)
			tmp+=list[k];
			ans.push_back(tmp);
		}
	
	}
	sort(ans.begin(),ans.end());
	//cout<<ans.size()<<endl;
	cout<<ans[ans.size()-m];
}


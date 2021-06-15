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
	for(int i=1;i<=n;i++)
	{
		
		for(int j=0;j<n-i+1;j++)
		{ 
			int tmp=0;
			for(int k=j;k<j+i;k++)
			tmp+=list[k];
			//cout<<tmp<<"\n";
			ans.push_back(tmp);
		}
	
	}
	sort(ans.begin(),ans.end());
	//cout<<ans.size()<<endl;
	cout<<ans[ans.size()-m];
}


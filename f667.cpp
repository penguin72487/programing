#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a;
	vector<int> val;
	while(cin>>a&&a!=EOF)
	{
		val.push_back(a);
	}
	int k;
	cin>>k;
	sort(val.begin(),val.end());
	cout<<val[val.size()-k]<<endl;
} 

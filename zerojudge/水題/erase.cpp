#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string a;
	while(cin>>a)
	{
		vector <int> l;
		int i;
		for(i=0;i<l.size();i++)
			l.push_back(l[i]);
		reverse(l.begin(),l.end());
		cout<<"YES"<<endl;
		i=1;
	
		while(l[i]==0)
		{
			cout<<"YES"<<endl;
			//l.erase(l.begin()+i);
			cout<<i<<endl;
			i++;
		}
		for(;i<l.size();i++)
		cout<<l[i];
	}
}


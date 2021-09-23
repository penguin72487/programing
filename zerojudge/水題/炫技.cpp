#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
	string val,val2;
	vector <int> ans;
	char k;
	int i,j;
void pl(string val,string val2)
{
	
	for(i=0;i<max(val.length(),val2.length());i++)
		ans.push_back(val+val2-2*'0'));
	
	
};
void mi(string val,string val2)
{
	
};
void ti(string val,string val2)
{
	
};
void di(string val,string val2)
{
	
};
int main()
{
	string val,val2;
	vector <int> ans;
	char k;
	cin>>val>>k>>val2;
	reverse(val.begin(),val.end());
	reverse(val2.begin(),val2.end());
	for(i=0;i<s_val.length();i++)
	val.push_back(s_val[i]);
	for(i=0;i<s_val2.length();i++)
	val.push_back(s_val2[i]);
	switch (k)
	{
		case '+':
			pl(val,val2);
		break;
		case '-':
			pl(val,val2);
		break;
		case '*':
			pl(val,val2);
		break;
		case '/':
			pl(val,val2);
		break;
		
	}
	
	for(i=0;i<ans.size();i++)
	cout<<ans[i];
		
	
	
	
	
	
	
}

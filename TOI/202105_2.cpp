#include<iostream>
using namespace std;
bool big(string val,string val2);
void fn_cul(int n,int list[],string tmp);
string ans;
int main()
{
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++)
	{
		cin>>list[i];
	}
	
	fn_cul(n,list,"+");
	fn_cul(n,list,"-");

	if(!ans.length())
	{
		cout<<"0\n";
	}
	else
	{
		cout<<"1\n";
		cout<<list[0];
		for(int i=0;i<n-1;i++)
		{
			cout<<ans[i]<<list[i+1];
		}
		cout<<"\n";
	}

}
bool big(string val,string val2)
{
	if(val2.length()==0)
	{
		return 1;
	}
	for(int i=0;i<val.size();i++)
	{
		if(val[i]==val2[i])
		{
			continue;
		}
		else if(val[i]<val2[i])
		{
			return 1;
		}
		else
		{
			return 0;
		} 
	}
	return 1;
}
void fn_cul(int n,int list[],string tmp)
{
	if(n==2)
	{
		int sum=list[0];
		for(int i=0;i<tmp.size();i++)
		{
			if(tmp[i]=='+')
			{
				sum+=list[i+1];
			}
			else
			{
				sum-=list[i+1];
			}
		}
		
		if(sum==0)
		{
			
			if(big(tmp,ans))
			{
				
				ans=tmp;
			}
		}
		return;
	}
	tmp.push_back('+');
	fn_cul(n-1,list,tmp);
	tmp.pop_back();
	tmp.push_back('-');
	fn_cul(n-1,list,tmp);
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
	string s_val,s_val2;
	vector <int> val,val2,ans;
	char k;
	int i,j;
void pl()
{	
	vector <int> more;
	if(val.size()!=val2.size())//�P��Ʀ�� 
		{
			if(val.size()>val2.size())
			{
				for(i=val2.size();i<val.size();i++)
				more.push_back(val[i]);
			}
			else
			{
				for(i=val.size();i<val2.size();i++)
				more.push_back(val2[i]);
			}
			
		}				
	for(i=0;i<min(val.size(),val2.size());i++) 
		{
			ans.push_back(val[i]+val2[i]);
		}
	
	
	for(i=0;i<ans.size();i++)						//�Τ@�i�� 
	{
		if(ans[i]>9)
		 {
    		ans[i+1]+=ans[i]%10;
    	ans[i]=ans[i]%10;
   		}
	}
	
	
	for(i=0;i<ans.size();i++)//�P��Ʀ�� 
		ans.push_back(more[i]);
	
}
void mi()
{



};
void ti()
{
	
};
void di()
{
	
};
int main()
{
	
	while (cin>>s_val>>k>>s_val2)
	{
		
	reverse(s_val.begin(),s_val.end());//���� 
	reverse(s_val2.begin(),s_val2.end());//���� 
	cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
	
	for(i=0;i<s_val.length();i++)//����svector�}�C 
	val.push_back(s_val[i]);
	for(i=0;i<s_val2.length();i++)//����svector�}�C 
	val2.push_back(s_val2[i]);

	for(i=0;i<val.size();i++)
	cout<<"val "<<val[i];
	cout<<endl;
	for(i=0;i<val2.size();i++)
	cout<<"val2 "<<val2[i];
	cout<<endl;

	switch (k)
	{
		case '+':
			pl();
		break;
		case '-':
			mi();
		break;
		case '*':
			ti();
		break;
		case '/':
			di();
		break;
		
	}
	
	for(i=0;i<ans.size();i++)
	cout<<ans[ans.size()-i];
		
	
	
	
	
		
	}
}

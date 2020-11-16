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
void pll(int a,int b)
{
	ans.push_back(a+b);
}
void pl()
{	
	vector <int> more;
	
	if(val.size()!=val2.size())//同位數行動 
		{
			if(val.size()>val2.size())
			{
				for(i=val2.size();i<val.size();i++)
					cout<<val[val.size()-i-1];
			}
			else
			{
				for(i=val.size();i<val2.size();i++)
					cout<<val2[val2.size()-i-1];
			}
			 
		}			
	for(i=0;i<min(val.size(),val2.size());i++) 
		{
			pll(val[i],val2[i]);
		}
	
	

}
void mii(int a,int b)
{
	
};
void mi()
{



};
void tii()
{
	
};
void ti()
{
	
};
void dii()
{
	
};
void di()
{
	
};
int main()
{
	
	while (cin>>s_val>>k>>s_val2)
	{
		
	reverse(s_val.begin(),s_val.end());//反轉 
	reverse(s_val2.begin(),s_val2.end());//反轉 
	//cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
	
	for(i=0;i<s_val.length();i++)//反轉存vector陣列 
	val.push_back(s_val[i]-'0');
	for(i=0;i<s_val2.length();i++)//反轉存vector陣列 
	val2.push_back(s_val2[i]-'0');
/*
	for(i=0;i<val.size();i++)
	cout<<"val "<<val[i];
	cout<<endl;
	for(i=0;i<val2.size();i++)
	cout<<"val2 "<<val2[i];
	cout<<endl;
	*/

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
	
		for(i=0;i<ans.size();i++)						//統一進位 
	{
		if(ans[i]>9)
		 {
		 	if(ans.size()==i+1)
		 		ans.push_back(ans[i]/10);
		 	else
    			ans[i+1]+=ans[i]/10;
    	ans[i]=ans[i]%10;
   		}
	}
	
	
	for(i=0;i<ans.size();i++)
	cout<<ans[ans.size()-i-1];
	ans.clear();
	val.clear();
	val2.clear();
		
	
	
	
	
		
	}
}

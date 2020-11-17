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
		for(i=0;i<val.size();i++) 
		{
			ans.push_back(val[i]+val2[i]);
		}
	
	
	

}
void mii(int a,int b)
{
	
};
void mi()
{
	if(s_val==s_val2)
		cout<<"0"<<endl;

	for(i=0;i<val.size();i++) 
		{
			ans.push_back(val[i]-val2[i]);
			//cout<<ans[i]<<" "; 
		}
};
void tii()
{
	
};
void ti()
{
	ans.assign(val.size()+val2.size(),0);//reserve + 初始化為 0 
	for(i=0;i<val.size();i++)
	{
		for(j=0;j<val2.size();j++)
		{  
			if(val[i]!=0&&val2[j]!=0)
			{
					ans[i+j]+=val[i]*val2[j];
					//cout<<val[i]<<"*"<<val2[j]<<" + ";
			}
			
			//cout<<ans[i+j]<<" ";
				
			//	cout<<val[i]<<"*"<<val2[j]<<"*"<<i*10<<" + ";
		//	cout<<ans[i]<<"="<<val[i]<<"*"<<val2[j]<<"*"<<i*10<<" + ";
		}
		
	}
	cout<<endl;
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
		for(i=0;i<max(s_val.length(),s_val2.length());i++)
		{
			if(k=='-'&&s_val.length()!=s_val2.length()&&max(s_val.length(),s_val2.length())==s_val2.length())
			{
					swap(s_val,s_val2);
					cout<<"-";
				break;
			}
			else if(s_val[i]<s_val2[i]||s_val.length()!=s_val2.length()&&max(s_val.length(),s_val2.length())==s_val2.length())
			{
				swap(s_val,s_val2);
				break;
			}
		}

	reverse(s_val.begin(),s_val.end());//反轉 
	reverse(s_val2.begin(),s_val2.end());//反轉 
	//cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
	val.assign(max(s_val.length(),s_val2.length()),0);
	val2.assign(max(s_val.length(),s_val2.length()),0);
	for(i=0;i<s_val.length();i++)//反轉存vector陣列 
		val[i]=s_val[i]-'0';
	for(i=0;i<s_val2.length();i++)//反轉存vector陣列 
		val2[i]=s_val2[i]-'0';


/*
	for(i=0;i<val.size();i++)
	cout<<val[i];
	cout<<endl;
	for(i=0;i<val2.size();i++)
	cout<<val2[i];
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
   		if(ans[i]<0)
   		{
   			ans[i+1]--;
   			ans[i]+=10; 
		   }
	}
	reverse(ans.begin(),ans.end());
	i=0;
	while(ans[i]==0)
	i++;
			
	for(;i<ans.size();i++)
	cout<<ans[i];
	cout<<endl;
	ans.clear();
	val.clear();
	val2.clear();
		
	
	
	
	
		
	}
}

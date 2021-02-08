#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
	vector <int> ans;
	char k;
	int i,j;

void pl(vector <int> val,vector <int> val2)
{				
		for(i=0;i<val.size();i++) 
			ans.push_back(val[i]+val2[i]);
}

void mi(vector <int> val,vector <int> val2)
{
	
	for(i=0;i<val.size();i++) 
			ans.push_back(val[i]-val2[i]);
}
void ti(vector <int> val,vector <int> val2)
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

void di(vector <int> val,vector <int> val2)
{
		
}
int main()
{
	string s_val,s_val2;
	vector <int> val,val2;
	
	while (cin>>s_val>>k>>s_val2)
	{
		int n=max(s_val.length(),s_val2.length());
		
	if(s_val.length()<s_val2.length())
	{
			swap(s_val,s_val2);
		//cout<<"!\n";
		if(k=='-')
					cout<<"-";
		
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
	
	
	
	
	for(i=0;i<n;i++)
		{
			if(s_val==s_val2||s_val.length()>s_val.length())
			break;
			else if(val[n-i]>val2[n-i])
			break;
			else if (val[n-i]==val2[n-i])
			continue;
			else if(val[n-i]<val2[n-i]) 
			{
				swap(val,val2);
			//	cout<<"$\n";
				if(k=='-')
					cout<<"-";
			break;
			}
		}

/*
	for(i=0;i<val.size();i++)
	cout<<val[i];
	cout<<endl;
	for(i=0;i<val2.size();i++)
	cout<<val2[i];
	cout<<endl;*/
	
	

	switch (k)
	{
		case '+':
			pl(val,val2);
		break;
		case '-':
			if(s_val==s_val2)
			{
				cout<<"0"<<endl;
				break;
			}
		
		
			mi(val,val2);
		break;
		case '*':
			ti(val,val2);
		break;
		case '/':
			di(val,val2);
		break;
		
	}
	
	for(i=0;i<ans.size();i++) 	//統一進位 
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

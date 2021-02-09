#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
	vector <int> ans;
	char k;
	int i,j;
bool zero(vector <int> val)
{
	if(count(val.begin(),val.end(),0)==val.size())
	return 1;
	else
	return 0;
}
bool big(vector <int> val,vector <int> val2)
{

	int n=max(val.size(),val2.size());
	while(*(val.end()-1)==0&&val.size()>val2.size())
	{
		val.erase(val.end()-1);
	} 
	while(*(val2.end()-1)==0&&val2.size()>1)
	{
		val2.erase(val2.end()-1);
	} 
	if(zero(val)==1)
	return 1;
	if(zero(val2)==1)
	return 0;
	for(int i=0;i<n;i++)
		{
			if(val.size()<val2.size())
			return 1;
			else if(val.size()>val2.size())
			return 0;
			else if(val[n-i-1]>val2[n-i-1])
			return 0;
			else if (val[n-i-1]==val2[n-i-1])
			continue;
			else if(val[n-i-1]<val2[n-i-1]) 
			{
				return 1;
			}
		}
	return 0;
	
} 
void pl(vector <int> val,vector <int> val2)
{				
		for(int i=0;i<val.size();i++) 
			ans.push_back(val[i]+val2[i]);
}

void mi(vector <int> val,vector <int> val2)
{	

	for(int i=0;i<val.size()-val2.size();i++) 
	{
		val2.push_back(0);		
	}
	for(int i=0;i<val.size();i++) 
	{
		ans.push_back(val[i]-val2[i]);		
	}
	for(int i=0;i<ans.size();i++) 	//統一進位 
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
	while(*(ans.end()-1)==0&&ans.size()>1)
			{
				ans.erase(ans.end()-1);
			} 
			
}
void ti(vector <int> val,vector <int> val2)
{
	ans.assign(val.size()+val2.size(),0);//reserve + 初始化為 0 
	for(int i=0;i<val.size();i++)
	{
		for(int j=0;j<val2.size();j++)
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
	vector <int> ans_di,val_di,val2_di;
	
	val_di.assign(val.begin(),val.end());
	val2_di.assign(val.size()-val2.size(),0); 
	
	for(int j=0;j<val2.size();j++)
		val2_di.push_back(val2[j]);
	/*
	for(int j=0;j<val2_di.size();j++)
			cout<<val2_di[j];
			cout<<endl;
			*/
	/*
	for(i=0;i<val_di.size();i++)
	cout<<val_di[i];
	cout<<endl;
	for(i=0;i<val2_di.size();i++)
	cout<<val2_di[i];
	cout<<endl;
	*/
	while(val2_di.size()>=val2.size())
	//while(!zero(val2_di)) 
	{
		//cout<<"YES"<<endl;
		int i=0;
		for(;!big(val_di,val2_di)&&val2_di.size()>=val2.size();i++)
		{
			
			mi(val_di,val2_di);
			//cout<<"哈哈哈"<<endl; 
			while(*(ans.end()-1)==0&&ans.size()>val2_di.size())
			{
				ans.erase(ans.end()-1);
			} 
			/*
			cout<<"val_di =  ";
			for(int j=0;j<val_di.size();j++)
			cout<<val_di[j];
			cout<<endl;
			cout<<"哈哈哈"<<endl; 
			cout<<"val2_di = ";
			for(int j=0;j<val2_di.size();j++)
			cout<<val2_di[j];
			cout<<endl;
			
			cout<<"計算ans = ";
			for(int j=0;j<ans.size();j++)
			cout<<ans[j];
			cout<<endl;
			
			*/
			val_di.clear();
			val_di.assign(ans.begin(),ans.end());
			/*
			cout<<"val_di = ";
			for(int j=0;j<val_di.size();j++)
			cout<<val_di[j];
			cout<<endl;
			*/
			ans.clear();
			
			//cout<<i<<endl;
		
			
			
		}
		//cout<<"i = "<<i<<endl;
		ans_di.push_back(i);
		val2_di.erase(val2_di.begin());
		//val2_di.push_back(0);
		/*
		if(big(val_di,val2_di))
		continue;
	*/
		
	}
	ans.clear();
	//cout<<"fXXK"<<endl;
	/*
	for(int j=0;j<ans_di.size();j++)
			cout<<ans_di[j];
			cout<<endl;
			*/
			/*
	i=0;
	while(ans_di[i]==0)
	i++;
	ans.assign(ans_di.begin()+i,ans_di.end());
	*/
	ans.assign(ans_di.begin(),ans_di.end());
	ans_di.clear();
	val.clear();
	val2.clear();
	reverse(ans.begin(),ans.end());
	/*
	for(int j=0;j<ans.size();j++)
			cout<<ans[j];
			cout<<endl;
			*/
		
};




int main()
{
	string s_val,s_val2;
	vector <int> val,val2;
	
	while (cin>>s_val>>k>>s_val2)
	{
		if(k=='/')
		{
			if(s_val=="0")
			{
				cout<<"0"<<endl;
				continue; 
				
			}
			if(s_val2=="1")
			{
				cout<<s_val2<<endl;
				continue;
			}
		}
		
		 int n=max(s_val.length(),s_val2.length());

	reverse(s_val.begin(),s_val.end());//反轉 
	reverse(s_val2.begin(),s_val2.end());//反轉 
	//cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
	/*
	val.assign(max(s_val.length(),s_val2.length()),0);
	val2.assign(max(s_val.length(),s_val2.length()),0);
	*/
	val.assign(s_val.length(),0);
	if(k=='-')
	val2.assign(max(s_val.length(),s_val2.length()),0);
	else
	val2.assign(s_val2.length(),0);
	for(i=0;i<s_val.length();i++)//反轉存vector陣列 
		val[i]=s_val[i]-'0';
	for(i=0;i<s_val2.length();i++)//反轉存vector陣列 
		val2[i]=s_val2[i]-'0';
	
	
	
	/*
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
				cout<<"$\n";
				if(k=='-')
					cout<<"-";
			break;
			}
		}
		*/
	
	if(big(val,val2)==1)
	{
		swap(val,val2);
		if(k=='-')
		cout<<"-";
		else if(k=='/')
		{
			cout<<"0"<<endl;
			continue;	
		}	
	}
		
	
	

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
	/*
	for(i=0;i<ans.size();i++)
	cout<<ans[i];
	cout<<endl;
	*/
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
	//cout<<"ans = ";
	for(;i<ans.size();i++)
	cout<<ans[i];
	cout<<endl;
	ans.clear();
	val.clear();
	val2.clear();
	
			
	}
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
	vector <int> ans;


bool zero(vector <int> val);  //檢查是否為0 是回傳1  
bool big(vector <int> val,vector <int> val2);//比大小，val2>val1時回傳1 
void pl(vector <int> val,vector <int> val2);
void mi(vector <int> val,vector <int> val2);
void ti(vector <int> val,vector <int> val2);
void di(vector <int> val,vector <int> val2);
int main()
{
	char k;
	string s_val,s_val2;
	vector <int> val,val2;
	
	while (cin>>s_val>>k>>s_val2)
	{
		if(k=='/')
		{
			if(s_val=="0")
			{
				cout<<"0\n";
				return 0;
				
			}
			else if(s_val2=="1")
			{
				cout<<s_val<<"\n";
				return 0;
			}
		}
		else if(k=='*')
		{
			if(s_val=="0"||s_val2=="0")
			{
				cout<<"0\n";
				return 0;
			}
			else if(s_val2=="1")
			{
				cout<<s_val<<"\n";
				return 0;
			}
			
		}
		else if(k=='-')
		{
			if(s_val==s_val2)
			{
				cout<<"0\n";
				return 0;
			}
			
		}

	reverse(s_val.begin(),s_val.end());//反轉 
	reverse(s_val2.begin(),s_val2.end());//反轉 
	val.assign(s_val.length(),0);
	if(k=='-')
	val2.assign(max(s_val.length(),s_val2.length()),0);
	else
	val2.assign(s_val2.length(),0);
	for(int i=0;i<s_val.length();i++)//反轉存vector陣列 
		val[i]=s_val[i]-'0';
	for(int i=0;i<s_val2.length();i++)//反轉存vector陣列 
		val2[i]=s_val2[i]-'0';
	
	
	

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
	reverse(ans.begin(),ans.end());
	int i=0;
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

bool zero(vector <int> val)  //檢查是否為0 是回傳1  
{
	if(count(val.begin(),val.end(),0)==val.size())
	return 1;
	else
	return 0;
}
bool big(vector <int> val,vector <int> val2)//比大小，val2>val1時回傳1 
{

	int n=max(val.size(),val2.size());
	while(*(val.end()-1)==0&&val.size()>val2.size())//把頭的0去掉 
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
		while(*(val.end()-1)==0&&val.size()>1)
		{
			val.erase(val.end()-1);
		}
	
		while(*(val2.end()-1)==0&&val2.size()>1)
		{
			val2.erase(val2.end()-1);
		}
	if(big(val,val2)==1)
	{
		swap(val,val2);	
	}
	/*
	for(auto it=val.begin();it!=val.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<" + ";
	for(auto it=val2.begin();it!=val2.end();it++)
	{
		cout<<*it<<" ";
	}	
	cout<<"\n";	
	*/		
	ans.clear();
		{
		vector<int>::iterator it=val.begin();
		vector<int>::iterator jt=val2.begin();
		for(;jt!=val2.end();it++,jt++) 
		ans.push_back(*it+*jt);
		for(;it!=val.end();it++) 
			ans.push_back(*it);
			
		}		
	//cout<<" e04\n";
	for(vector<int>::iterator it=ans.begin();it!=ans.end();it++) 	//統一進位 
	{
		if(*it>9)
		{
		 	if(it+1==ans.end())
		 		ans.push_back(*it/10);
		 	else
		 	{
		 		
		 		*(++it)+=*it/10;
				 it--;	
			}
    	*it%=10;
   		}
   		if(*it<0)
   		{
   			*(it+1)--;
   			*it+=10; 
		}
	}
	//cout<<"MMMMMMMM\n";
	while(*(ans.end()-1)==0&&ans.size()>1)
	{
		ans.erase(ans.end()-1);
	} 
	
	cout<<"ans=\n";
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
	
			
}

void mi(vector <int> val,vector <int> val2)
{	
	if(big(val,val2)==1)
	{
		swap(val,val2);	
	}
	/*
	for(auto it=val.begin();it!=val.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<" - ";
	for(auto it=val2.begin();it!=val2.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
	*/
	ans.clear();
	{
		vector<int>::iterator it=val.begin();
		vector<int>::iterator jt=val2.begin();
		for(;jt!=val2.end();it++,jt++) 
		ans.push_back(*it-*jt);
		for(;it!=val.end();it++) 
			ans.push_back(*it);
			
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
	/*
	cout<<"ans=\n";
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
	*/
			
}
void ti(vector<int> val,vector<int> val2)
{
	if(big(val,val2)==1)
	{
		swap(val,val2);	
	}
	if(val.size()&1)
	val.push_back(0);
	if(val2.size()&1)
	val2.push_back(0);
	if(val.size()!=val2.size())
	{
		while(val.size()<val2.size())
		{
			val.push_back(0);
		}
		while(val.size()>val2.size())
		{
			val2.push_back(0);
		}
	}
	/*
	for(auto it=val.begin();it!=val.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<" * ";
	for(auto it=val2.begin();it!=val2.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n end \n ";
	*/
	ans.clear();

	//ans.assign(s_val.length()+s_val2.length(),0);//reserve + 初始化為 0 
	if(val.size()<=2&&val2.size()<=2)
	{
		while(val.size()!=2)
		{
			val.push_back(0);
		}
		while(val2.size()!=2)
		{
			val2.push_back(0);
		}
		//cout<<"YES\n";
		ans.clear();
		ans.assign(val.size()+val2.size(),0);//reserve + 初始化為 0 
	
		for(int i=0;i<val.size();i++)
		{
			for(int j=0;j<val2.size();j++)
			{  
				ans[i+j]+=val[i]*val2[j];
				if(ans[i+j]>9)
				{	
				 	if(ans.size()==i+j+1)
				 		ans.push_back(ans[i+j]/10);
				 	else
   	 				ans[i+j+1]+=ans[i+j]/10;
   	 				ans[i+j]=ans[i+j]%10;
   				}
			}
			
		}
		
		/* 
		cout<<"ans=\n";
		for(auto it=ans.begin();it!=ans.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<"\n";
		*/
		while(*(ans.end()-1)==0&&ans.size()>1)
		{
			ans.erase(ans.end()-1);
		} 
		return ;
	}
	//cout<<"FUCK"<<endl;
	
	vector<int> a,b,c,d;
	int n=val.size();
	n/=2;
	b.assign(val.begin(),val.begin()+n);
	a.assign(val.begin()+n,val.end());
	d.assign(val2.begin(),val2.begin()+n);
	c.assign(val2.begin()+n,val2.end());
	
	vector<int> formul_1,formul_2,formul_3,formul_4;
	ti(a,c);
	formul_1.assign(ans.begin(),ans.end());
//	cout<<"第1\n";
	ti(b,d);
	formul_2.assign(ans.begin(),ans.end());
//	cout<<"第1POP\n";
//	cout<<"第2\n";
	vector<int> temp,temp2;
	pl(a,b);
	temp.assign(ans.begin(),ans.end());
	pl(c,d);
	temp2.assign(ans.begin(),ans.end());
	ti(temp,temp2);
	formul_3.assign(ans.begin(),ans.end());
//	cout<<"第2POP\n";
//	cout<<"第3\n";
	pl(formul_1,formul_2);
	temp.clear();
	temp.assign(ans.begin(),ans.end());
	mi(formul_3,temp);
	formul_4.assign(ans.begin(),ans.end());
//	cout<<"第3POP\n";
//	cout<<"第4\n";
	for(int i=0;i<2*n;i++)
	{
		formul_1.insert(formul_1.begin(),0);
	}
	for(int i=0;i<n;i++)
	{
		formul_4.insert(formul_4.begin(),0);
	}
	pl(formul_1,formul_2);
	temp.clear();
	temp.assign(ans.begin(),ans.end());
	pl(temp,formul_4);
//	cout<<"第4POP\n";
	

	
}

void di(vector <int> val,vector <int> val2)
{
	vector <int> ans_di,val_di,val2_di;
	
	val_di.assign(val.begin(),val.end());
	val2_di.assign(val.size()-val2.size(),0); 
	
	for(int j=0;j<val2.size();j++)
		val2_di.push_back(val2[j]);

	while(val2_di.size()>=val2.size())
	{
		int i=0;
		for(;!big(val_di,val2_di)&&val2_di.size()>=val2.size();i++)
		{
			
			mi(val_di,val2_di);
			while(*(ans.end()-1)==0&&ans.size()>val2_di.size())
			{
				ans.erase(ans.end()-1);
			} 
			val_di.clear();
			val_di.assign(ans.begin(),ans.end());
			ans.clear();
		}
		ans_di.push_back(i);
		val2_di.erase(val2_di.begin());		
	}
	ans.clear();
	ans.assign(ans_di.begin(),ans_di.end());
	ans_di.clear();
	val.clear();
	val2.clear();
	reverse(ans.begin(),ans.end());	
}

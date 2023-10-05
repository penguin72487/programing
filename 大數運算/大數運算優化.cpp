#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
	vector <int> ans;

	int i,j;
bool zero(vector <int> val);  //檢查是否為0 是回傳1  
bool big(vector <int> val,vector <int> val2);//比大小，val2>val1時回傳1 
void pl(vector <int> val,vector <int> val2);
void mi(vector <int> val,vector <int> val2);
void ti(vector <int> val,vector <int> val2);
void di(vector <int> val,vector <int> val2);
int main()
{
	
	vector <int> val,val2;
	char k;
	string s_val,s_val2;
	while (cin>>s_val>>k>>s_val2)
	{
	//	cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
		if(k=='/')
		{
			if(s_val=="0")
			{
				cout<<"0"<<endl;
				return 0;
				
			}
			else if(s_val2=="1")
			{
				cout<<s_val<<endl;
				return 0;
			}
		}
		else if(k=='*')
		{
			if(s_val2=="0")
			{
				cout<<"0"<<endl;
				return 0;
			}
			else if(s_val2=="1")
			{
				cout<<s_val<<endl;
				return 0;
			}
			
		}
		else if(k=='-')
		{
			if(s_val==s_val2)
			{
				cout<<"0"<<endl;
				return 0;
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
	val2.assign(s_val2.length(),0);
	{
	
	auto it=s_val.begin();
	vector<int>::iterator jt=val.begin();
	for(;it!=s_val.end()&&jt!=val.end();jt++,it++)
	//for(i=0;i<s_val.length();i++)//反轉存vector陣列 
		*jt=*it-'0';
	auto i2=s_val2.begin();
	vector<int>::iterator j2=val2.begin();
	for(;i2!=s_val2.end()&&j2!=val2.end();j2++,i2++)
	//for(i=0;i<s_val2.length();i++)//反轉存vector陣列 
		*j2=*i2-'0';	
	}

	
	
	
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
			return 0;	
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
			//cout<<"加法喔"<<endl; 
			pl(val,val2);
		break;
		case '-':
			//cout<<"減法喔"<<endl; 
			mi(val,val2);
		break;
		case '*':
			//cout<<"乘法喔"<<endl; 
			ti(val,val2);
		break;
		case '/':
			//cout<<"除法喔"<<endl; 
			di(val,val2);
		break;
		
	}
	/*
	for(i=0;i<ans.size();i++)
	cout<<ans[i];
	cout<<endl;
	*/
	/*
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
	*/
	reverse(ans.begin(),ans.end());
	//cout<<"ans = ";
	for(vector<int>::iterator it =ans.begin();it!=ans.end();it++)
	cout<<*it;
	cout<<endl;
	ans.clear();
	val.clear();
	val2.clear();		
	}
	return 0;
}

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
	{
		vector<int>::iterator it=val.end()-1;
		vector<int>::iterator jt=val2.end()-1;
		for(;it!=val.begin()||jt!=val2.begin();it--,jt--)
		{
			if(val.size()<val2.size())
			return 1;
			else if(val.size()>val2.size())
			return 0;
			else if(*it>*jt)
			return 0;
			else if (*it==*jt)
			continue;
			else if(*it<*jt) 
			{
				return 1;
			}
		}
		
	}
		
	return 0;
	
} 
void pl(vector <int> val,vector <int> val2)
{		
		{
		vector<int>::iterator it=val.begin();
		vector<int>::iterator jt=val2.begin();
		for(;jt!=val2.end();it++,jt++) 
		ans.push_back(*it+*jt);
		for(;it!=val.end();it++) 
			ans.push_back(*it);
			
		}		

	for(vector<int>::iterator it=ans.begin();it!=ans.end();it++) 	//統一進位 
	{
		if(*it>9)
		{
		 	if(it+1==ans.end())
		 		ans.push_back(*it/10);
		 	else
    			*(it+1)+=*it/10;
    	*it=*it%10;
   		}
   		if(*it<0)
   		{
   			*(it+1)--;
   			*it+=10; 
		}
	}
	

		
}

void mi(vector <int> val,vector <int> val2)
{	
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
			
}
void ti(vector <int> val,vector <int> val2)
{
	ans.assign(val.size()+val2.size(),0);//reserve + 初始化為 0 
	
	for(int i=0;i<val.size();i++)
	{
		for(int j=0;j<val2.size();j++)
		{  
					ans[i+j]+=val[i]*val2[j];
					//cout<<val[i]<<"*"<<val2[j]<<" + ";
			
			//cout<<ans[i+j]<<" ";
				
			//	cout<<val[i]<<"*"<<val2[j]<<"*"<<i*10<<" + ";
		//	cout<<ans[i]<<"="<<val[i]<<"*"<<val2[j]<<"*"<<i*10<<" + ";
		}
		
	}
	for(vector<int>::iterator it=ans.begin();it!=ans.end();it++) 	//統一進位 
	{
		if(*it>9)
		{
		 	if(it+1==ans.end())
		 		ans.push_back(*it/10);
		 	else
    			*(it+1)+=*it/10;
    	*it=*it%10;
   		}
   		if(*it<0)
   		{
   			*(it+1)--;
   			*it+=10; 
		}
	}
	while(*(ans.end()-1)==0&&ans.size()>1)
	{
		ans.erase(ans.end()-1);
	} 
}

void di(vector <int> val,vector <int> val2)
{
	vector <int> ans_di,val_di,val2_di;
	
	val_di.assign(val.begin(),val.end());
	val2_di.assign(val.size()-val2.size(),0); 
	
	for(vector<int>::iterator it=val2.begin();it!=val2.end();it++)
		val2_di.push_back(*it);
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
	/*
	for(int j=0;j<ans.size();j++)
			cout<<ans[j];
			cout<<endl;
			*/
		
}

#include<iostream>
#include<algorithm>
#include<string>
//using namespace std;
using std::reverse;
using std::string;
using std::cout;
using std::cin;
using std::endl;

bool zero(string s_val);  //檢查是否為0 是回傳1  
bool small(string s_val,string s_val2);//比大小，val<val2時回傳1 
string pl(string s_val,string s_val2);
string mi(string s_val,string s_val2);
string ti(string s_val,string s_val2);
int main()
{
	string ans;
	cin.tie(0);
	cout.tie(0);
	char k='*';
	string s_val="5678",s_val2="1234";
	//while (cin>>s_val>>k>>s_val2)
	{
	//	cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
		
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
			if(s_val2=="0")
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
		
		for(auto it=s_val.begin();it!=s_val.end();it++)
		*it-='0';
		for(auto it=s_val2.begin();it!=s_val2.end();it++)
		*it-='0';
	reverse(s_val.begin(),s_val.end());//反轉 
	reverse(s_val2.begin(),s_val2.end());//反轉 
	if(small(s_val,s_val2)==1)
	{
		swap(s_val,s_val2);
		if(k=='-')
		cout<<"-";
		else if(k=='/')
		{
			cout<<"0\n";
			return 0;	
		}	
	}
		
	


	switch (k)
	{
		case '+':
			//cout<<"加法喔"<<endl; 
		ans=pl(s_val,s_val2);
		break;
		case '-':
			//cout<<"減法喔"<<endl; 
		ans=mi(s_val,s_val2);
		break;
		case '*':
			//cout<<"乘法喔"<<endl; 
		ans=ti(s_val,s_val2);
		break;

		
	}
	/*
	for(i=0;i<ans.length();i++)
	cout<<ans[i];
	cout<<endl;
	*/
	/*
	for(int i=0;i<ans.length();i++) 	//統一進位 
	{
		if(ans[i]>9)
		{
		 	if(ans.length()==i+1)
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
	while(*(ans.end()-1)<=0&&ans.length()>1)
	{
		ans.erase(ans.end()-1);
	}
	reverse(ans.begin(),ans.end());
	//cout<<"ans = ";

	for(auto it =ans.begin();it!=ans.end();it++)
	*it+='0';
	cout<<ans<<"\n";
	ans.clear();
	s_val.clear();
	s_val2.clear();		
	}
	return 0;
}

bool zero(string s_val)
{
	if(count(s_val.begin(),s_val.end(),0)==s_val.length())
	return 1;
	else
	return 0;
}
bool small(string s_val,string s_val2)
{

	while(*(s_val.end()-1)==0&&s_val.length()>s_val2.length())
	{
		s_val.erase(s_val.end()-1);
	} 
	while(*(s_val2.end()-1)==0&&s_val2.length()>1)
	{
		s_val2.erase(s_val2.end()-1);
	} 
	if(zero(s_val)==1)
	return 1;
	if(zero(s_val2)==1)
	return 0;
	{
		auto it=s_val.end()-1;
		auto jt=s_val2.end()-1;
		for(;it!=s_val.begin()||jt!=s_val2.begin();it--,jt--)
		{
			if(s_val.length()<s_val2.length())
			return 1;
			else if(s_val.length()>s_val2.length())
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
string pl(string s_val,string s_val2)
{		
	for(auto it=s_val.begin();it!=s_val.end();it++)
	*it+='0';
	for(auto it=s_val2.begin();it!=s_val2.end();it++)
	*it+='0';
	cout<<s_val<<" "<<s_val2<<endl;
	for(auto it=s_val.begin();it!=s_val.end();it++)
	*it-='0';
	for(auto it=s_val2.begin();it!=s_val2.end();it++)
	*it-='0';

	string ans;
		{
		auto it=s_val.begin();
		auto jt=s_val2.begin();
		for(;jt!=s_val2.end();it++,jt++) 
		ans+=(*it+*jt);
		for(;it!=s_val.end();it++) 
			ans.push_back(*it);
			
		}		
	cout<<"pppppp\n";
	for(auto it=ans.begin();it!=ans.end();it++) 	//統一進位 
	{
		if(*it>9)
		{
		 	if(it+1==ans.end())
		 		ans+=(*it/10);
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
	
	return ans;
		
}

string mi(string s_val,string s_val2)
{	
	string ans;
		{
		auto it=s_val.begin();
		auto jt=s_val2.begin();
		for(;jt!=s_val2.end();it++,jt++) 
		{
			ans+=(*it-*jt);
			//cout<<*it<<"-"<<*jt<<"="<<*it-*jt<<endl;
			
		}
		
		for(;it!=s_val.end();it++) 
			ans.push_back(*it);
			
		}
	
	for(int i=0;i<ans.length();i++) 	//統一進位 
	{
		if(ans[i]>9)
		{
		 	if(ans.length()==i+1)
		 		ans+=(ans[i]/10);
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
	while(*(ans.end()-1)==0&&ans.length()>1)
	{
		ans.erase(ans.end()-1);
	} 
	return ans;	
}
string ti(string s_val,string s_val2)
{
	string ans;

	//ans.assign(s_val.length()+s_val2.length(),0);//reserve + 初始化為 0 
	if(s_val.length()<=2&&s_val2.length()<=2)
	{
		cout<<"YES\n";
		ans.assign(s_val.length()+s_val2.length(),0);//reserve + 初始化為 0 
	
		for(int i=0;i<s_val.length();i++)
		{
			for(int j=0;j<s_val2.length();j++)
			{  
				ans[i+j]+=s_val[i]*s_val2[j];
				if(ans[i+j]>9)
				{	
				 	if(ans.length()==i+j+1)
				 		ans.push_back(ans[i+j]/10);
				 	else
   	 				ans[i+j+1]+=ans[i+j]/10;
   	 				ans[i+j]=ans[i+j]%10;
   				}
			}
			
		}
		cout<<"90\n";
		return ans;
	}
	cout<<"FUCK"<<endl;
	
	string a,b,c,d;
	int n=s_val.length();
	n/=2;
	b.assign(s_val.begin(),s_val.begin()+n);
	a.assign(s_val.begin()+n,s_val.end());
	d.assign(s_val2.begin(),s_val2.begin()+n);
	c.assign(s_val2.begin()+n,s_val2.end());
	
	for(auto it=a.begin();it!=a.end();it++)
	*it+='0';
	for(auto it=b.begin();it!=b.end();it++)
	*it+='0';
	cout<<a<<endl;
	cout<<b<<endl;
	for(auto it=a.begin();it!=a.end();it++)
	*it-='0';
	for(auto it=b.begin();it!=b.end();it++)
	*it-='0';
	string formul_1=ti(a,c);
	cout<<"1\n";
	string formul_2=ti(b,d);
	cout<<"2\n";
	string formul_3=ti(pl(a,b),pl(c,d));
	cout<<"3\n";
	string formul_4=mi(formul_3,pl(formul_1,formul_2));
	cout<<"4\n";
	for(int i=0;i<2*n;i++)
	{
		formul_1+=("0"-'0');
	}
	for(int i=0;i<n;i++)
	{
		formul_4+=("0"-'0');
	}
	ans=pl(pl(formul_1,formul_2),formul_4);
	

	
}


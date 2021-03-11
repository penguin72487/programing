#include<iostream>
#include<algorithm>
#include<string>
//using namespace std;
using std::reverse;
using std::string;
using std::cout;
using std::cin;

string ans;

bool zero(string s_val);  //檢查是否為0 是回傳1  
bool small(string s_val,string s_val2);//比大小，val<val2時回傳1 
void pl(string s_val,string s_val2);
string mi(string s_val,string s_val2);
void ti(string s_val,string s_val2);
void di(string s_val,string s_val2);
int main()
{
	cin.tie(0);
	cout.tie(0);
	char k='-';
	string s_val,s_val2;
	while (cin>>s_val>>k>>s_val2)
	{
	//	cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
		for(auto it=s_val.begin();it!=s_val.end();it++)
		*it-='0';
		for(auto it=s_val2.begin();it!=s_val2.end();it++)
		*it-='0';
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
			pl(s_val,s_val2);
		break;
		case '-':
			//cout<<"減法喔"<<endl; 
			mi(s_val,s_val2);
		break;
		case '*':
			//cout<<"乘法喔"<<endl; 
			ti(s_val,s_val2);
		break;
		case '/':
			//cout<<"除法喔"<<endl; 
			di(s_val,s_val2);
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
void pl(string s_val,string s_val2)
{		
		{
		auto it=s_val.begin();
		auto jt=s_val2.begin();
		for(;jt!=s_val2.end();it++,jt++) 
		ans+=(*it+*jt);
		for(;it!=s_val.end();it++) 
			ans.push_back(*it);
			
		}		

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
	

		
}

string mi(string s_val,string s_val2)
{	
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
void ti(string s_val,string s_val2)
{
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
					//cout<<val[i]<<"*"<<val2[j]<<" + ";
			
			//cout<<ans[i+j]<<" ";
				
			//	cout<<val[i]<<"*"<<val2[j]<<"*"<<i*10<<" + ";
		//	cout<<ans[i]<<"="<<val[i]<<"*"<<val2[j]<<"*"<<i*10<<" + ";
		}
		
	}
	
	while(*(ans.end()-1)==0&&ans.length()>1)
	{
		ans.erase(ans.end()-1);
	} 
}

void di(string s_val,string s_val2)
{
	string ans_di,val_di,val2_di;

	val_di=s_val;
	val2_di.assign(s_val.length()-s_val2.length(),0); 
	for(auto it=s_val2.begin();it!=s_val2.end();it++)
		val2_di+=(*it);
	/*
	for(int j=0;j<val2_di.length();j++)
			cout<<val2_di[j];
			cout<<endl;
			*/
	/*
	for(i=0;i<val_di.length();i++)
	cout<<val_di[i];
	cout<<endl;
	for(i=0;i<val2_di.length();i++)
	cout<<val2_di[i];
	cout<<endl;
	*/
	while(val2_di.length()>=s_val2.length())
	//while(!zero(val2_di)) 
	{
		//cout<<"YES"<<endl;
		int i=0;
		for(;!small(val_di,val2_di)&&val2_di.length()>=s_val2.length();i++)
		{
			
			val_di=mi(val_di,val2_di);
			//cout<<"哈哈哈"<<endl; 
			//val_di.assign(ans.begin(),ans.end());
			ans.clear();

			
		}

		ans_di+=(i);
		val2_di.erase(val2_di.begin());

		
	}
	ans.clear();

	ans.assign(ans_di.begin(),ans_di.end());
	ans_di.clear();
	s_val.clear();
	s_val2.clear();
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
	reverse(ans.begin(),ans.end());

		
}

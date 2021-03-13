#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/*
using std::reverse;
using std::string;
using std::cout;
using std::cin;
using std::endl;
*/
bool zero(string s_val); //檢查是否為0 是回傳1  
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
string ti(string val,string val2)
{
	string ans;
	if(small(val,val2)==1)
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
		return ans;
	}
	//cout<<"FUCK"<<endl;
	
	string a,b,c,d;
	int n=val.size();
	n/=2;
	b.assign(val.begin(),val.begin()+n);
	a.assign(val.begin()+n,val.end());
	d.assign(val2.begin(),val2.begin()+n);
	c.assign(val2.begin()+n,val2.end());
	
	string formul_1,formul_2,formul_3,formul_4;
	ti(a,c);
	formul_1.assign(ans.begin(),ans.end());
//	cout<<"第1\n";
	ti(b,d);
	formul_2.assign(ans.begin(),ans.end());
//	cout<<"第1POP\n";
//	cout<<"第2\n";
	string temp,temp2;
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
	ans=pl(temp,formul_4);
//	cout<<"第4POP\n";
	return ans;

	
}


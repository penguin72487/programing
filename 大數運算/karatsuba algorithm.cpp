#include<iostream>
#include<algorithm>
#include<fstream> 
#include<string>
#include<sstream>
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
string pl(string val,string val2);
string mi(string val,string val2);
string ti(string val,string val2);
string di(string val,string val2);
int main()
{
	string ans;
	cin.tie(0);
	cout.tie(0);
	fstream file;
	file.open("乘法.txt"); 
	char k;
	string s_val,s_val2;
	file>>s_val>>k>>s_val2;
	
	//while (cin>>s_val>>k>>s_val2)
	{
		//cout<<s_val<<"\n"<<k<<"\n"<<s_val2<<"\n";
		
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
		case '/':
		ans=di(s_val,s_val2);
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
string pl(string val,string val2)
{	
	/*	
	for(auto it=val.begin();it!=val.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<" + ";
	for(auto it=val2.begin();it!=val2.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<"\n";
	*/
	while(*(val.end()-1)==0&&val.length()>1)
	{
		val.erase(val.end()-1);
	}	
	while(*(val2.end()-1)==0&&val2.length()>1)
	{
		val2.erase(val2.end()-1);
	}
	if(small(val,val2)==1)
	{
		swap(val,val2);	
	}
	string ans;
		{
		auto it=val.begin();
		auto jt=val2.begin();
		for(;jt!=val2.end();it++,jt++) 
		ans+=(*it+*jt);
		for(;it!=val.end();it++) 
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
   		else if(ans[i]<0)
   		{
   			ans[i+1]--;
   			ans[i]+=10; 
		}
	}
	
	while(*(ans.end()-1)==0&&ans.length()>1)
	{
		ans.erase(ans.end()-1);
	}
	/* 
	cout<<"ans= ";
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<"\n";
	*/
	return ans;
		
}

string mi(string val,string val2)
{	
	/*
	for(auto it=val.begin();it!=val.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<" - ";
	for(auto it=val2.begin();it!=val2.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<"\n";
	*/
	string ans;
		{
		auto it=val.begin();
		auto jt=val2.begin();
		for(;jt!=val2.end();it++,jt++) 
		{
			ans+=(*it-*jt);
			//cout<<*it<<"-"<<*jt<<"="<<*it-*jt<<endl;
			
		}
		
		for(;it!=val.end();it++) 
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
   		else if(ans[i]<0)
   		{
   			ans[i+1]--;
   			ans[i]+=10; 
		}
	}
	while(*(ans.end()-1)==0&&ans.length()>1)
	{
		ans.erase(ans.end()-1);
	} 
	/*
	cout<<"ans= ";
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<"\n";
	*/
	return ans;	
}
string ti(string val,string val2)
{
	string ans;
	if(small(val,val2)==1)
	{
		swap(val,val2);	
	}
	if(val.length()&1)
	val.push_back(0);
	if(val2.length()&1)
	val2.push_back(0);
	if(val.length()!=val2.length())
	{
		while(val.length()<val2.length())
		{
			val.push_back(0);
		}
		while(val.length()>val2.length())
		{
			val2.push_back(0);
		}
	}
	/*
	for(auto it=val.begin();it!=val.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<" * ";
	for(auto it=val2.begin();it!=val2.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<"\n end \n ";
	*/

	//ans.assign(s_val.length()+s_val2.length(),0);//reserve + 初始化為 0 
	if(val.length()<=2&&val2.length()<=2)
	{
		while(val.length()!=2)
		{
			val.push_back(0);
		}
		while(val2.length()!=2)
		{
			val2.push_back(0);
		}
		ans.assign(val.length()+val2.length(),0);//reserve + 初始化為 0 
	
		for(int i=0;i<val.length();i++)
		{
			for(int j=0;j<val2.length();j++)
			{  
				ans[i+j]+=val[i]*val2[j];
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
		
		/* 
		cout<<"ans=\n";
		for(auto it=ans.begin();it!=ans.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<"\n";
		*/
		while(*(ans.end()-1)==0&&ans.length()>1)
		{
			ans.erase(ans.end()-1);
		} 
		return ans;
	}
//	cout<<"FUCK"<<endl;
	
	string a,b,c,d;
	int n=val.length();
	n/=2;
	b.assign(val.begin(),val.begin()+n);
	a.assign(val.begin()+n,val.end());
	d.assign(val2.begin(),val2.begin()+n);
	c.assign(val2.begin()+n,val2.end());
	
	string formul_1,formul_2,formul_3,formul_4;
	
	formul_1=ti(a,c);
//	cout<<"第1\n";
	formul_2=ti(b,d);
//	cout<<"第1POP\n";
//	cout<<"第2\n";
	formul_3=ti(pl(a,b),pl(c,d));
//	cout<<"第2POP\n";
//	cout<<"第3\n";
	formul_4=mi(formul_3,pl(formul_1,formul_2));
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
	ans=pl(pl(formul_1,formul_2),formul_4);
//	cout<<"第4POP\n";
	return ans;

	
}

string di(string val,string val2)
{
	string ans_di,val_di,val2_di;
	string ans;
	val_di=val;
	val2_di.assign(val.length()-val2.length(),0); 
	for(auto it=val2.begin();it!=val2.end();it++)
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
	while(val2_di.length()>=val2.length())
	//while(!zero(val2_di)) 
	{
		//cout<<"YES"<<endl;
		int i=0;
		for(;!small(val_di,val2_di)&&val2_di.length()>=val2.length();i++)
		{
			
			val_di=mi(val_di,val2_di);
			//cout<<"哈哈哈"<<endl; 
			//val_di.assign(ans.begin(),ans.end());

			
		}

		ans_di+=(i);
		val2_di.erase(val2_di.begin());

		
	}
	

	ans=ans_di;
	ans_di.clear();
	val.clear();
	val2.clear();
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
   		else if(ans[i]<0)
   		{
   			ans[i+1]--;
   			ans[i]+=10; 
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
		
}


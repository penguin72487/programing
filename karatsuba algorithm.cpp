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
bool zero(string s_val); //�ˬd�O�_��0 �O�^��1  
bool small(string s_val,string s_val2);//��j�p�Aval<val2�ɦ^��1 
string pl(string val,string val2);
string mi(string val,string val2);
string ti(string val,string val2);
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
	reverse(s_val.begin(),s_val.end());//���� 
	reverse(s_val2.begin(),s_val2.end());//���� 
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
			//cout<<"�[�k��"<<endl; 
		ans=pl(s_val,s_val2);
		break;
		case '-':
			//cout<<"��k��"<<endl; 
		ans=mi(s_val,s_val2);
		break;
		case '*':
			//cout<<"���k��"<<endl; 
		ans=ti(s_val,s_val2);
		break;

		
	}
	/*
	for(i=0;i<ans.length();i++)
	cout<<ans[i];
	cout<<endl;
	*/
	/*
	for(int i=0;i<ans.length();i++) 	//�Τ@�i�� 
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
	for(auto it=ans.begin();it!=ans.end();it++) 	//�Τ@�i�� 
	{
		if(*it>9)
		{
		 	if(it==ans.end()-1)
		 		ans.push_back(*it/10);
		 	else
		 	{
		 		auto jt=it;
		 		it++;
		 		*(it)+=*jt/10;
				 it--;
			}
    			
    	*it%=10;
   		}
	}
	while(*(ans.end()-1)==0&&ans.length()>1)
	{
		ans.erase(ans.end()-1);
	} 
	cout<<"ans= ";
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<"\n";
	return ans;
		
}

string mi(string val,string val2)
{	

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
	
	for(int i=0;i<ans.length();i++) 	//�Τ@�i�� 
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
	cout<<"ans= ";
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<char(*it+'0')<<" ";
	}
	cout<<"\n";
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
	

	//ans.assign(s_val.length()+s_val2.length(),0);//reserve + ��l�Ƭ� 0 
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
		ans.assign(val.length()+val2.length(),0);//reserve + ��l�Ƭ� 0 
	
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
	cout<<"FUCK"<<endl;
	
	string a,b,c,d;
	int n=val.length();
	n/=2;
	b.assign(val.begin(),val.begin()+n);
	a.assign(val.begin()+n,val.end());
	d.assign(val2.begin(),val2.begin()+n);
	c.assign(val2.begin()+n,val2.end());
	
	string formul_1,formul_2,formul_3,formul_4;
	
	formul_1=ti(a,c);
	cout<<"��1\n";
	formul_2=ti(b,d);
	cout<<"��1POP\n";
	cout<<"��2\n";
	formul_3=ti(pl(a,b),pl(c,d));
	cout<<"��2POP\n";
	cout<<"��3\n";
	formul_4=mi(formul_3,pl(formul_1,formul_2));
	cout<<"��3POP\n";
	cout<<"��4\n";
	for(int i=0;i<2*n;i++)
	{
		formul_1.insert(formul_1.begin(),0);
	}
	for(int i=0;i<n;i++)
	{
		formul_4.insert(formul_4.begin(),0);
	}
	ans=pl(pl(formul_1,formul_2),formul_4);
	cout<<"��4POP\n";
	return ans;

	
}


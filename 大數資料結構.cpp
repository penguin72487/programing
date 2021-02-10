#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
	vector <int> ans;

	int i,j;




class bignum{
};
bool zero(vector <int> val);  //檢查是否為0 是回傳1  
bool big(vector <int> val,vector <int> val2);//比大小，val2>val1時回傳1 
bool big(bignum val,bignum val2);
void pl(vector <int> val,vector <int> val2);
void mi(vector <int> val,vector <int> val2);
void ti(vector <int> val,vector <int> val2);
void di(vector <int> val,vector <int> val2);
int main()
{
	
	bignum val,val2;
	char k;
	string s_val,s_val2;
	while (cin>>s_val>>k>>s_val2)
	{
	
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

	switch (k)
	{
		case '+':
			//cout<<"加法喔"<<endl; 
			//val+val2;
		break;
		case '-':
			//cout<<"減法喔"<<endl; 
			//val-val2;
		break;
		case '*':
			//cout<<"乘法喔"<<endl; 
			//val*val2;
		break;
		case '/':
			//cout<<"除法喔"<<endl; 
			//val/val2;
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
bool big(bignum val,bignum val2)
{


	while(*(val.val.end()-1)==0&&val.val.size()>val2.size())
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
class bignum
{
	
	public: vector <int> val;//存反值 
	public: string str;//存正值 
	
	//以下是輸入的多載有支援字串int long long int;   大數 << 
	
	operator << (bignum val2)
	{
		
		val.assign(val2.val.begin(),val2.val.end());
		str="";
		for(vector<int>::iterator it=val.begin();it!=val.end();it++)
		{
			str+=to_string(*it);
		}
		reverse(str.begin(),str.end());
		
	};
	 
	operator << (string s_val)
	{
		str=s_val;
		reverse(s_val.begin(),s_val.end());//反轉 
		val.assign(s_val.length(),0);
		{
	
		auto it=s_val.begin();
		vector<int>::iterator jt=val.begin();
		for(;it!=s_val.end()&&jt!=val.end();jt++,it++)
			*jt=*it-'0';	
		}
		
	};
	operator << (vector<int> val2)
	{
		val.assign(val2.rbegin(),val2.rend());
		
	};
	operator << (int a)
	{
		while(a>0)
		{
			val.push_back(a%10);
			a/=10;
		}

		
	};
	operator << (long long int a)
	{
		while(a>0)
		{
			val.push_back(a%10);
			a/=10;
		}

		
	};
	operator >> (string val2)
	{
		if(str.length())
		{
			val2=str;
		}
		else
		{
			for(vector<int>::iterator it=val.begin();it!=val.end();it++)
			{
				val2+=to_string(*it);
			}
			reverse(val2.begin(),val2.end());

		}
	}
	operator = (bignum val2)
	{
		val.assign(val2.val.begin(),val2.val.end());
	}
	bignum operator+(bignum val2)
    {
        bignum ans;
        
        {
		vector<int>::iterator it=val.begin();
		vector<int>::iterator jt=val2.val.begin();
		for(;jt!=val2.val.end();it++,jt++) 
		ans.val.push_back(*it+*jt);
		for(;it!=val.end();it++) 
			ans.val.push_back(*it);
			
		}		

	for(vector<int>::iterator it=ans.val.begin();it!=ans.val.end();it++) 	//統一進位 
	{
		if(*it>9)
		{
		 	if(it+1==ans.val.end())
		 		ans.val.push_back(*it/10);
		 	else
    			*(it+1)+=*it/10;
    	*it=*it%10;
   		}
	}
	str="";
	for(vector<int>::iterator it=ans.val.begin();it!=ans.val.end();it++)
		{
			str+=to_string(*it);
		}
		reverse(str.begin(),str.end());
        return ans;
    }	
    bignum operator-( bignum val2 )
    {
        bignum ans;
        
        {
		vector<int>::iterator it=val.begin();
		vector<int>::iterator jt=val2.val.begin();
		for(;jt!=val2.val.end();it++,jt++) 
		ans.val.push_back(*it-*jt);
		for(;it!=val.end();it++) 
			ans.val.push_back(*it);
			
		}
	
		for(int i=0;i<ans.val.size();i++) 	//統一進位 
		{
			if(ans.val[i]>9)
			{
			 	if(ans.val.size()==i+1)
			 		ans.val.push_back(ans.val[i]/10);
			 	else
	    			ans.val[i+1]+=ans.val[i]/10;
	    	ans.val[i]=ans.val[i]%10;
	   		}
	   		if(ans.val[i]<0)
	   		{
	   			ans.val[i+1]--;
	   			ans.val[i]+=10; 
			}
		}
		while(*(ans.val.end()-1)==0&&ans.val.size()>1)
		{
			ans.val.erase(ans.val.end()-1);
		} 
	str="";
	for(vector<int>::iterator it=ans.val.begin();it!=ans.val.end();it++)
		{
			str+=to_string(*it);
		}
		reverse(str.begin(),str.end());
	return ans;
    }	
    bignum operator*( bignum val2 )
    {
    	bignum ans;
    	ans.val.assign(val.size()+val2.val.size(),0);//reserve + 初始化為 0 
	
		for(int i=0;i<val.size();i++)
		{
			for(int j=0;j<val2.val.size();j++)
			{  
						ans.val[i+j]+=val[i]*val2.val[j];
			}
			
		}
		for(vector<int>::iterator it=ans.val.begin();it!=ans.val.end();it++) 	//統一進位 
		{
			if(*it>9)
			{
			 	if(it+1==ans.val.end())
			 		ans.val.push_back(*it/10);
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
		while(*(ans.val.end()-1)==0&&ans.val.size()>1)
		{
			ans.val.erase(ans.val.end()-1);
		} 
		str="";
		for(vector<int>::iterator it=ans.val.begin();it!=ans.val.end();it++)
		{
			str+=to_string(*it);
		}
		reverse(str.begin(),str.end());
    	return ans;
	}
	bignum operator/( bignum val2 )
	{
		bignum ans;
	vector <int> ans_di,val_di,val2_di;
	val_di.assign(val.begin(),val.end());
	val2_di.assign(val.size()-val2.val.size(),0); 
	
	for(vector<int>::iterator it=val2.val.begin();it!=val2.val.end();it++)
		val2_di.push_back(*it);
	while(val2_di.size()>=val2.val.size())
	{
		int i=0;
		for(;!big(val_di,val2_di)&&val2_di.size()>=val2.val.size();i++)
		{
			
			mi(val_di,val2_di);
			while(*(ans.val.end()-1)==0&&ans.val.size()>val2_di.size())
			{
				ans.val.erase(ans.val.end()-1);
			} 
			val_di.clear();
			val_di.assign(ans.val.begin(),ans.val.end());
			ans.val.clear();
				
		}
		ans_di.push_back(i);
		val2_di.erase(val2_di.begin());		
	}
	ans.val.clear();
	ans.val.assign(ans_di.begin(),ans_di.end());
	ans_di.clear();
		for(vector<int>::iterator it=ans.val.begin();it!=ans.val.end();it++) 	//統一進位 
	{
		if(*it>9)
		{
		 	if(it+1==ans.val.end())
		 		ans.val.push_back(*it/10);
		 	else
    			*(it+1)+=*it/10;
    	*it=*it%10;
   		}
	}
    str="";
	for(vector<int>::iterator it=ans.val.begin();it!=ans.val.end();it++)
		{
			str+=to_string(*it);
		}
	reverse(ans.val.begin(),ans.val.end());
	return ans;
	
		
	}
	bool zero(bignum val)
	{
			if(count(val.val.begin(),val.val.end(),0)==val.val.size())
			return 1;
			else
			return 0;
	}
	
}; 

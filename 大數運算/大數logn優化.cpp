#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
	vector <unsigned long long> ans;


bool zero(vector <unsigned long long> val);  //�ˬd�O�_��0 �O�^��1  
bool big(vector <unsigned long long> val,vector <unsigned long long> val2);//��j�p�Aval2>val1�ɦ^��1 
void pl(vector <unsigned long long> val,vector <unsigned long long> val2);
void mi(vector <unsigned long long> val,vector <unsigned long long> val2);
void ti(vector <unsigned long long> val,vector <unsigned long long> val2);
void di(vector <unsigned long long> val,vector <unsigned long long> val2);
vector <unsigned long long> stov(string val,int n);
int main()
{
	fstream file;
	file.open("���k1.txt"); 
	char k;
	string s_val,s_val2;
	file>>s_val>>k>>s_val2;
	vector <unsigned long long> val,val2;
	
	//while (cin>>s_val>>k>>s_val2)
	{
		if(k=='/')
		{
			if(s_val=="0")
			{
				cout<<"0"<<endl;
				return 0; 
				
			}
			if(s_val2=="1")
			{
				cout<<s_val2<<endl;
				return 0;
			}
		}
	vector <unsigned long long> temp=stov(s_val,8);
	

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

	for(int i=0;i<ans.size();i++) 	//�Τ@�i�� 
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

bool zero(vector <unsigned long long> val)  //�ˬd�O�_��0 �O�^��1  
{
	if(count(val.begin(),val.end(),0)==val.size())
	return 1;
	else
	return 0;
}
bool big(vector <unsigned long long> val,vector <unsigned long long> val2)//��j�p�Aval2>val1�ɦ^��1 
{

	int n=max(val.size(),val2.size());
	while(*(val.end()-1)==0&&val.size()>val2.size())//���Y��0�h�� 
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
vector <unsigned long long> stov(string val,int n)
{
	vector <unsigned long long> ans;
	for(int i=val.length();i>0;i-=n)
	{
		string temp;
		temp.assign(val.end()-1,val.end()-1-n);
		ans.push_back(stoi(temp));
	}
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
	return ans;	
} 
void pl(vector <unsigned long long> val,vector <unsigned long long> val2)
{				
		for(int i=0;i<val.size();i++) 
			ans.push_back(val[i]+val2[i]);
}

void mi(vector <unsigned long long> val,vector <unsigned long long> val2)
{	

	for(int i=0;i<val.size()-val2.size();i++) 
	{
		val2.push_back(0);		
	}
	for(int i=0;i<val.size();i++) 
	{
		ans.push_back(val[i]-val2[i]);		
	}
	for(int i=0;i<ans.size();i++) 	//�Τ@�i�� 
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
void ti(vector <unsigned long long> val,vector <unsigned long long> val2)
{
	ans.assign(val.size()+val2.size(),0);//reserve + ��l�Ƭ� 0 
	for(int i=0;i<val.size();i++)
	{
		for(int j=0;j<val2.size();j++)
		{  
			if(val[i]!=0&&val2[j]!=0)
			{
					ans[i+j]+=val[i]*val2[j];		
			}
		}
		
	}
	cout<<endl;
}

void di(vector <unsigned long long> val,vector <unsigned long long> val2)
{
	vector <unsigned long long> ans_di,val_di,val2_di;
	
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
	reverse(ans.begin(),ans.end());	//���׬O���� 
}

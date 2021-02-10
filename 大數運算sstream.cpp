#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
//vector <unsigned long long> factorial;
 stringstream factorial;
int i,j,k;
unsigned long long a=1152921504606846976;//2^60

void  f(int n)
{
	
factorial<<1;
	for(i=1;i<=n;i++)
	{
			/*
			int num = i;
			while(num>=5)
			{
				k+=i/5;
				num/=5;
			}
			*/
			for(k=0;k<factorial.str().length();k++)
			{
				factorial.str()[k]=(factorial.str()[k]-'0')*2+'0';
			//	cout<<factorial.str()[k]<<" "<<i<<" ";
				
			}
			cout<<factorial.str()<<endl;
			for(j=0;j<factorial.str().length();j++)						//統一進位 
		{
				if(factorial.str()[j]>9+'0')
		 	{
		 		if(factorial.str().length()==j+1)
		 			factorial<<((factorial.str()[j])-'0'/10+'0');
		 		else
    				factorial.str()[j+1]+=((factorial.str()[j])-'0'/10+'0');
    			factorial.str()[j]=(factorial.str()[j]-'0')%10+'0';
   			}
		}
	}
	string s=factorial.str();
	reverse(s.begin(),s.end());
	factorial.str()=s;

			
}

void out()
{
		i=0;
	while(factorial.str()[i]==0)  //去數字頭的0 
	i++;
			
	for(;i<factorial.str().length();i++)
	printf("%d",factorial.str()[i]);
	printf("\n");
	factorial.clear();
	factorial.str("");
}
int main ()
{
	int n;
	cout<<a<<endl;
	while(cin>>n&&n!=0)
	{
		
		f(n);
		out();
	}
	
} 

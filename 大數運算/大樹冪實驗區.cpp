#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream> 
#include<string>
using namespace std;
vector <unsigned long long> factorial;
vector <string> s;
int i,j,k;

string  f(int n)
{
	if(s[n]!="0")
	{
		return s[n];
	}
	else
	{
		retuen f(n-1)*2;
	}
	
			
}

int main ()
{
	int n;
	unsigned long long a=1152921504606846976;
	cout<<a<<endl;
	s.assign(10000,"0");
	s[0]="1";
	while(cin>>n&&n!=0)
	{
			cout<<f(n)<<endl;	
		
	}
	
} 

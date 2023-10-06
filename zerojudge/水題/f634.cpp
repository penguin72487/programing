#include<iostream>
#include<map>
using namespace std;
struct pen{ 
	int a;//­xºØ 
	int b;//­x¶¥
	 
};
int main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	pen so;
	map<string,pen> o_so;
	for(i=0;i>m;i++)
	{
		string s;
		int a,b;
		cin>>s>>a>>b;
		o_so[s].a=a;
		o_so[s].b=b;
	}	
} 

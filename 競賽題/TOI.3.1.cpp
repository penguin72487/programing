#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int h,m,s,t;
	while(cin>>h>>m>>s>>t)
	{
		int int_time;
		int_time=h*60+m;
		int_time+=(90*t);
		int_time=(int_time%(36*60)+36*60)%(36*60);
		h=int_time/60;
		m=int_time%60; 
		cout<<h<<":";
		if(m<10)
		cout<<"0";
		cout<<m<<":";
		if(s<10)
		cout<<"0";
		cout<<s<<endl;
	}
}

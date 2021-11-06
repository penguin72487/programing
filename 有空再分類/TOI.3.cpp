#include<iostream>
using namespace std;
int main()
{
	int s,e,a;
	cin>>s>>e>>a;
	int i,j,h=s,day=1,re=1;
	while(h<e)
	{
		if(day==11*re-1||day==11*re-2)
		h=h;
		else if(day==11*re)
		re++;
		else if(day%3==0)
		h+=h/3;
		else 
		h+=h/10;
		//printf("a %d h %d re %d day %d\n",a,h,re,day);
		if(a-re<0)
		break;
		day++;
	}
		if(a-re<0)
		cout<<"unsalable"<<endl;
		else
		cout<<day<<endl;
	
}

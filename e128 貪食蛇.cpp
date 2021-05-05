#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
	unsigned int a;
	while(cin>>a&&a)
	{
		float b,c;
		b=sqrt(a);
		c=int(b);
		if(b==c)
		{
			int tmp=c;
			if(tmp&1)
			{
				cout<<"1 "<<tmp<<endl;	
			}
			else 
			{
				cout<<tmp<<" 1"<<endl;			
			}	
		}
		else
		{
			int tmp=c;
			int num=((tmp+1)*(tmp+1)-tmp*tmp-1)>>1;
			if(tmp*tmp+num+1==a)
			{
				//cout<<"00\n";
				cout<<tmp+1<<" "<<tmp+1<<endl;	
			}
			else if(tmp*tmp+num+1<a)
			{
				
				if(tmp&1)
				{
					//cout<<"11\n";
					cout<<tmp+1<<" "<<((tmp+1)*(tmp+1)-a)%(tmp+1)+1<<endl;
				}
				else
				{
					//cout<<"12\n";
					
					cout<<((tmp+1)*(tmp+1)-a)%(tmp+1)+1<<" "<<tmp+1<<endl;
				}
				
			}	
			else
			{
				
				if(tmp&1)
				{
					//cout<<"21\n";
					cout<<(a-tmp*tmp)%(tmp+1)<<" "<<tmp+1<<endl;	
				}
				else
				{
					//cout<<"22\n";
					cout<<tmp+1<<" "<<(a-tmp*tmp)%(tmp+1)<<endl;
				}
			}
		}	
	}
	
}


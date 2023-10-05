#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{

	int p[10][7]={0};
	int n,m;
	bool out=0;
	cin>>n>>m;
	for(int i=n;i<m;i++)
	{

		int num=0;
		int k=i;
		while(k)
		{
			//cout<<"k= "<<k<<endl;
			//cout<<k%10<<" "<<int(log10(i))+1<<" ";
			if(p[k%10][int(log10(i))+1]!=0)
			{
				num+=p[k%10][int(log10(i))+1];
				//cout<<p[k%10][int(log10(i))+1]<<endl;
			}
			else
			{
				p[k%10][int(log10(i))+1]=pow(k%10,int(log10(i))+1);
				num+=p[k%10][int(log10(i))+1];
			}
			k/=10;
		}
		//cout<<"num= "<<num<<endl;
		if(num==i)
		{
			out=1;
			cout<<i<<" ";
			
		}

	}
			if(out==0)
		cout<<"none"<<endl;
		
	
}

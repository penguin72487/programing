#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n=2*n;
	int l[n],h=0;
	int i,j;
	for(i=0;i<n;i++)
	cin>>l[i];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			
			 if(l[i]==l[j])
			{
				
			for(int k=i+1;k<j;k++)
			{
			if(l[i]>l[k])
			{
				h++;
				cout<<l[i]<<endl;
			}
		}
		}
		}
	}
	cout<<h<<endl;
 } 

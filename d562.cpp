#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		vector <int> l;
		l.reserve(n);
		int i,j,a;
		for(i=0;i<n;i++)
		 cin>>l[i];
	
		
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				cout<<l[j]<<" ";
			
			}
				cout<<endl;
				
			reverse(l.begin(),l.end());
			l.pop_back(); 
		}
		
	}
	}


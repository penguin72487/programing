#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	int n=s.length();
	int m=t.length();
	int i,j;
	
	for(i=0;i<m;i++)
	{
		int loc;
		int u = 0 ;
		for(j=0;j<n;j++)
		{
		
			if(s[j]==t[i])
			{
				loc=j;
				s[j]=-12;
				cout<<loc+1<<" ";
				break;
			}
			
			
		  if (t[i]!=s[j]&&j==s.size()-1)
                u=-1;
        }
        if (u==-1)
        cout<<"X "; 
	}
	
}

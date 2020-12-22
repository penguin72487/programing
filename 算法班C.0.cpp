#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string s_a,s_b;
	
	string str_a="00000000000000000000000000";
	string str_b="00000000000000000000000000";
	//128­Ó0 
	cin>>s_a>>s_b;
	int n=s_a.length();
	int i,j;
	int ans=0;
	vector <char> a,b;
	for(i=0;i<n;i++)
	{
		a.push_back(s_a[i]);
		b.push_back(s_b[i]);
	}

	int dif=1;
	for(i=0;i<n;i++)
	{
	
		if(str_a[a[i]-97]=='0')
		{
			str_a[a[i]-97]=dif;
			s_a[i]=dif;
			dif++;
		continue;
		}
			s_a[i]=str_a[a[i]-97];
	}
	
	for(j=0;j<n;j++)
	{
		
	string str_a="00000000000000000000000000";
	string str_b="00000000000000000000000000";

		dif=1;
		for(i=0;i<n;i++)
		{
			
			if(str_b[b[i]-97]=='0')
			{
				str_b[b[i]-97]=dif;
				s_b[i]=dif;
				dif++;
			continue;
			}
			s_b[i]=str_b[b[i]-97];
		}
		b.push_back(b[0]);
		b.erase(b.begin());
		if(s_b==s_a)
		{
			ans++;
		}

	}
	cout<<ans<<endl;
	
	
}

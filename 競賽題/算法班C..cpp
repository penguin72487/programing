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
	cout<<s_a<<endl;
	cout<<s_b<<endl;
	int dif=1;
	for(i=0;i<n;i++)
	{
		//cout<<"AAAAAAAAA"<<endl;
		if(str_a[a[i]-97]=='0')
		{
			str_a[a[i]-97]=dif;
			s_a[i]=dif;
			dif++;
		continue;
		}
			s_a[i]=str_a[a[i]-97];
	}
	
	cout<<"N: "<<n<<endl;
	for(j=0;j<n;j++)
	{
		
	string str_a="00000000000000000000000000";
	string str_b="00000000000000000000000000";
	//	cout<<"NNNNNNNNN\n";
		dif=1;
		for(i=0;i<n;i++)
		{
			//cout<<"BBBBBBBBB"<<endl;
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
		cout<<"B: ";
		for(i=0;i<n;i++)
		cout<<b[i];
		cout<<endl;
		
		
		cout<<"s_A: ";
		for(i=0;i<n;i++)
		cout<<(int)s_a[i];
		cout<<endl;
		
		cout<<"s_B: ";
		for(i=0;i<n;i++)
		cout<<(int)s_b[i];
		cout<<endl;
		if(s_b==s_a)
		{
			ans++;
		}
	//	cout<<"NNNNNNNNN\n";
	}
	cout<<ans<<endl;
	/*
	cout<<"A: ";
	for(i=0;i<n;i++)
	cout<<a[i];
	cout<<endl;
	cout<<"B: ";
	for(i=0;i<n;i++)
	cout<<b[i];
	cout<<endl;
	*/
	/*
	cout<<"s_A: ";
	for(i=0;i<n;i++)
	cout<<(int)s_a[i];
	cout<<endl;
	cout<<"s_B: ";
	for(i=0;i<n;i++)
	cout<<(int)s_b[i];
	cout<<endl;
	*/
	//cout<<s_a<<endl;
	//cout<<s_b<<endl;
	//cout<<str_a<<endl;
	//cout<<str_b<<endl;
	
}

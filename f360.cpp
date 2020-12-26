#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string val;
while(cin>>val)
{
		
	reverse(val.begin(),val.end());
	int n=val.length();
	val[0]--;
	for(int i=0;i<n;i++)
	{
		if(val[i]<'0')
   		{
   			val[i+1]--;
   			val[i]+=10; 
		}
	}
	reverse(val.begin(),val.end());
	int i=0;
	while(val[i]=='0')
	i++;
		
	for(;i<n;i++)
	cout<<(val[i]-'0');
	cout<<endl; 	
}

}

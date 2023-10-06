#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string l,k;
	cin>>l>>k;
	int i,j;
	for(i=0;i<n;i++)
	{
		int m=l.length();
		if(find(k.begin()+i,k.begin()+i+m,l)!=string::npos))
		j++;
		
	}
	if(n==j)
	cout<<"YES"<<endl;
	else 
	cout<<"NO"<<endl;
	
}

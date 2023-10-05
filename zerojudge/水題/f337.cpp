#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n*2>m*8)
	cout<<"Not enough"<<endl;
	else if(n*3<m*8)
	cout<<"Too much"<<endl;
	else 
	cout<<"Yes"<<endl;
}

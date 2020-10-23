#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
int main()
{
	int a;
	vector<int> n;
	n.reserve(100); 
	cin>>a;
	n[87]=a;
	cout <<n[87]<<endl;
	cout<<n.front()<<endl;
	cout<<n.back()<<endl;
 } 

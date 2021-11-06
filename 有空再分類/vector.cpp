#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
int main()
{
	int a;
	vector<int> n;
	vector<int> ten{1,0}; 
	while(cin>>a&&a!=-1)
	{
		n.push_back(a);
	}
	while(cin>>a)
	{
		n.erase(n.end()-1);
		for(int i=0;i<n.size();i++)
		cout<<n[i];
		cout<<endl;
		
	}
	
	/*n[87]=a;
	cout <<n[87]<<endl;
	cout<<n.front()<<endl;
	cout<<n.back()<<endl;
	*/
 } 

#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
int main()
{
	int a;
	vector<int> n;
	int* loc= n;
	n.reserve(100); 
	while(cin>>a)
	{
		n.push_back(a);
		cout<<&loc<<" "<<loc<<endl;
	}
	
	/*n[87]=a;
	cout <<n[87]<<endl;
	cout<<n.front()<<endl;
	cout<<n.back()<<endl;
	*/
 } 

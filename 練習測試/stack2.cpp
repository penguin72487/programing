#include<iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> stack;
	string n;	
	int i=0;
	while(cin>>n)
	{
		if(n=="push")
		{
			cin>>i;
			stack.push_back(i); 
		}
		else if(stack.empty())
		cout<<"nothing in stack\n";
		else
		{
			cout<<stack.back()<<endl;
			stack.pop_back();
		}
	}
	

	 
	
	
	
	
	
	}

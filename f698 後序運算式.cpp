#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	stringstream s;
	string tmp;
	int ans=0;
	//stack<char> sym;
	stack<int> val;
	getline(cin,tmp);
	s<<tmp;
	//cout<<s.str()<<endl;
	tmp.clear();

	while(getline(s,tmp,' '))
	{
		//cout<<tmp<<endl;
		if(tmp[0]>='0')
		{
			int int_a;
			int_a=stoi(tmp.c_str());
		//	cout<<int_a<<"p"<<endl;
			val.push(int_a);
			
		}
		else
		{
			
			char c_a;
			c_a=tmp[0];
			int a,b;
				
				a=val.top();
			//	cout<<a<<"pop"<<endl;
				val.pop();
				b=val.top();
			//	cout<<b<<"pop"<<endl;
				val.pop();
			//	cout<<a<<" ©M "<<b<<endl;
			 
			switch(tmp[0])
			{
				
				
				case '+':
				
				val.push(a+b);
				//cout<<val.top()<<endl;
				break;
				case '-':
				val.push(a-b);
				//cout<<val.top()<<endl;
				break;
				case '*':
				val.push(a*b);
				//cout<<val.top()<<endl;
				break;
				case '/':
				val.push(a/b);
				//cout<<val.top()<<endl;
				break;
			}
		}
	}
	cout<<val.top()<<endl;
}


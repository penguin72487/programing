#include<iostream>
#include<cmath>
using namespace std;
float q_sqrt(unsigned long long x);
int main()
{
	unsigned long long  a;
	while(cin>>a)
	{
		cout<<q_sqrt(a)<<endl;
		cout<<sqrt(a)<<endl;
	}
	
}
float q_sqrt(unsigned long long x) { 
	if(x == 0) return 0; 
	float result = x; 
	float xhalf = 0.5f*result; 
	int i = *(int*)&result; 
	i = 0x5f375a86- (i>>1); // what the fuck? 
	result = *(float*)&i; 
	result = result*(1.5f-xhalf*result*result); // Newton step, repeating increases accuracy 
	result = result*(1.5f-xhalf*result*result); 
	return 1.0f/result; 
}

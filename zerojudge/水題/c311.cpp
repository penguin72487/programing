#include<iostream>
using namespace std;
int mod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;
 
    return res;
}
int main()
{
	string s;
	while(cin>>s&&s!="-1")
	{
		cout<<mod(s,91)<<endl;
	}
}

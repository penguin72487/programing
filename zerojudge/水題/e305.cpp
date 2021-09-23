#include<iostream>
#include<algorithm>

using namespace std;
 
string tob(unsigned long long n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}
int main()
{
	unsigned long long a;
	while(cin>>a)
	{
		string s=tob(a);
		unsigned long long h=count(s.begin(),s.end(),'0');
		printf("%llu\n",(1<<h));
	}
	
	
}



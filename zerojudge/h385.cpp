#include <iostream>

using namespace std;
class rational_Number{
public:
	long long n=0;//numerator
	long long d=1;//denominator
    rational_Number(){

    }
    rational_Number(long long a, long long b){
        n = a;
        d = b;
    }
    void simple(){
        long long tmp=gcd(n,d);
        n/=tmp;
        d/=tmp;

    }
    void operator=(long long tmp){
        n=tmp;
    }
    long long gcd(long long a,long long b)
    {
        if(!b)
        return a;
        return gcd( b, a%b );
    }
    long long lcm(long long a,long long b)
	{
		return a*b/gcd(a,b); 
	}
    long double ld()
    {
        return (long double)n /(long double)d;
    }
    bool operator<(rational_Number other){
        return (this->ld() < other.ld());
    }

    rational_Number operator+(rational_Number tmp){
        rational_Number ans(tmp.d*n+d*tmp.n,d*tmp.d);
        ans.simple();
        return ans;
    }
    rational_Number operator/(long long tmp){
        rational_Number ans = *this;
        ans.d *= tmp;
        ans.simple();
        return ans;
    }
    friend ostream &operator<<(ostream &s, rational_Number ob)
	{
		if(ob.d==1)
        {
            s << ob.n;
        }
        else {
            s<<ob.n<<"/"<<ob.d;
        }
		return s;
	}
};

int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    long long t[4];
	long long i = 0;
	while (cin >> t[0] >> t[1] >> t[2] >> t[3])
	{
		if (t[0] == 0 && t[0] == t[1] && t[1] == t[2] && t[2] == t[3])
        {
            break;
        }
		++i;
        rational_Number a(t[1],t[0]);
        rational_Number b(t[3],t[2]);
        if (a<b)
		{
			cout << "Case #" << i << ": You owe me a beer!\n";
			
		}
        else 
        {
            cout << "Case #" << i << ": No beer for the captain.\n";
        }
            cout<<"Avg. arrival time: " <<(a+b)/2<<"\n";
    }
}
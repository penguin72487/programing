#include<iostream>
#include<sstream>
using namespace std;
class rational//¤À¼Æ¹Bºâ 
{
public:
	int a=0;//numerator
	char b='/';
	int c=1;
	rational()
	{
		
	}
	rational(int tmp)
	{
		a=tmp;
		
	}
	rational(int i_a,int i_c)
	{
		a=i_a;
		c=i_c;
		simple();
	}
	rational(string tmp)
	{
		
		stringstream ss(tmp);
		ss>>a;
		ss>>b;
		ss>>c;
		simple();
	}
	rational(const char tmp[])
	{
		
		stringstream ss(tmp);
		ss>>a;
		ss>>b;
		ss>>c;
		simple();
	}
//	void operator=(rational& tmp)
//	{
//		a=tmp.a;
//		b=tmp.b;
//		c=tmp.c;
//	}
	rational operator+ (int tmp)
	{
		rational ans=*this;
		ans.a+=tmp*c;
		return ans.simple();
	}
	rational operator- (int tmp)
	{
		rational ans=*this;
		ans.a-=tmp*c;
		return ans.simple();
	}
	rational operator* (int tmp)
	{
		rational ans=*this;

		ans.a*=tmp; 
		return ans.simple();
	}
	rational operator/ (int tmp)
	{
		rational ans=*this;
		ans.c*=tmp;
		return ans.simple();
	}
	rational operator+ (rational tmp)
	{
		rational ans=*this;
		int i_lcm=lcm(ans.c,tmp.c);
		ans.a=ans.a*(i_lcm/ans.a)+tmp.a*(i_lcm/tmp.a);
		return ans.simple();
	}
	rational operator- (rational tmp)
	{
		rational ans=*this;
		int i_lcm=lcm(ans.c,tmp.c);
		ans.a=ans.a*(i_lcm/ans.a)-tmp.a*(i_lcm/tmp.a);
		return ans.simple();
	}
	rational operator* (rational tmp)
	{
		rational ans=*this;
		ans.a*=tmp.a;
		ans.c*=tmp.c;
		return ans.simple();
	}
	rational operator/ (rational tmp)
	{
		rational ans=*this;
		ans*=tmp.pow(-1);
		return ans.simple();
	}
	
	void operator+=(int tmp)
	{
		a+=tmp*c;
		simple();
	}
	void operator-= (int tmp)
	{
		a-=tmp*c;
		simple();	
	}
	void operator*= (int tmp)
	{
		a*=tmp; 
		simple();
		
	}
	void operator/= (int tmp)
	{
		
		c*=tmp;
		simple();
	}
	void operator+= (rational tmp)
	{
	
		int i_lcm=lcm(c,tmp.c);
		a=a*(i_lcm/a)+tmp.a*(i_lcm/tmp.a);
		simple();
	}
	void operator-= (rational tmp)
	{
	
		int i_lcm=lcm(c,tmp.c);
		a=a*(i_lcm/a)-tmp.a*(i_lcm/tmp.a);
		simple();
	}
	void operator*= (rational tmp)
	{
	
		a*=tmp.a;
		c*=tmp.c;
		simple();
	}
	void operator/= (rational tmp)
	{
		*this*=tmp.pow(-1);
		simple();
		
		
	}
	int gcd( int a, int b )
{
    if(!b)
    return a;
    return gcd( b, a%b );
}
	rational simple()
	{
		
		int tmp=gcd(a,c);
		this->a/=tmp;
		this->c/=tmp;
		return *this;
	}
	rational pow(int n)
	{
		rational ans(1);
		rational A=*this;
		if(n>=0)
		{
			


			while(n)
			{
				if(n&1)
				{

					ans.a*=A.a;
					ans.c*=A.c;

				}
				A*=A;

				n >>= 1;

			}
		}
		else
		{
			swap(A.a,A.c);
			n*=-1;
			while(n)
			{

				if(n&1)
				{

					ans.a*=A.a;
					ans.c*=A.c;

				}
				A*=A;

				n >>= 1;

			}
			
		}
		return ans;
	}
	friend istream &operator>>(istream &s, rational& ob)
	{
		
		s>>ob.a;
		s>>ob.b;
		s>>ob.c;
		return s;
	}
	friend ostream &operator<<(ostream &s, rational ob)
	{
		if(ob.c!=1)
		s<<ob.a<<ob.b<<ob.c;
		else
		s<<ob.a;
		return s;
	}
	int lcm(int a,int b)
	{
		int i_gcd=gcd(a,b);
		return (a/i_gcd)*(b/i_gcd)*(i_gcd); 
	}
	

};
int gcd( int a, int b )
{
    if(!b)
    return a;
    return gcd( b, a%b );
}
int main()
{
	
	string ss="77/7";
	rational a="17857125/99999900";
	rational b="423/990";
	//cin>>a;
	cout<<b.simple()<<"\n";
	cout<<a.simple()<<endl;

}


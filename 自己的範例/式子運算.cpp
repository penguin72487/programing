#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
class rational//分數運算 
{
public:
	int a=0;
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
	bool operator==(int tmp)
	{
		if(c==1)
		{
			if(a==tmp)
			{
				return 1;
			}
		}
		return 0;
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
		return ans.simple();
	}
	friend istream &operator>>(ostream &s, rational& ob);
	friend ostream &operator<<(ostream &s, rational ob);
	int gcd( int a, int b )
	{
	    if(!b)
	    return a;
	    return gcd( b, a%b );
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
istream &operator>>(istream &s, rational& ob)
{
	
	s>>ob.a;
	s>>ob.b;
	s>>ob.c;
	return s;
}
ostream &operator<<(ostream &s, rational ob)
{
	if(ob.c!=1)
	s<<ob.a<<ob.b<<ob.c;
	else
	s<<ob.a;
	return s;
}
class numeral//數字or符號  e.g. -7 or X^2 
{	
public:
	char sign='+';
	rational pow=1;
	rational val=1;
	string letter;
	numeral(int tmp)
	{
		val=tmp;
	}
	numeral(const char tmp)
	{
		
	}
	friend ostream &operator<<(ostream &s,numeral ob);

};
ostream &operator<<(ostream &s,numeral ob)
{
	if(ob.letter.size()==0)
	{
		if(ob.sign=='+')
		{
			if(ob.pow==1)
			{
				s<<ob.val;
			}
		}
	}
	else
	{
		
	}
	return s;
}
class equation //多項式  e.g. -7*X^2+X+87  
{
	char sign;
	vector<numeral> list;
		
};
int main()
{
	
	string ss="77/7";
	rational a="77/8";
	rational b="64/7";
	//cin>>a;
	cout<<a/8<<"\n";
	a/=b;
	cout<<a<<endl;

}


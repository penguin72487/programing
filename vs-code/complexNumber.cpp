#include<iostream>
#include<cmath>
using namespace std;
class c_Num{
public : 
    c_Num(long double t_A,long double t_B)
    {
        a = t_A;
        b = t_B;
    }
    c_Num(long double t_A)
    {
        a = t_A;
        b = 0.0;
    }
    c_Num()
    {
        a = 0.0;
        b = 0.0;
    }
    long double a;
    long double b;
    /*
    void operator = (c_Num tmp)
    {
        a = tmp.a;
        b = tmp.b;
    }
    */
    void operator= (const c_Num& tmp)
    {
        a = tmp.a;
        b = tmp.b;
        //return *this;
    }
    c_Num operator *(c_Num tmp)
    {
        return c_Num(a*tmp.a-b*tmp.b,a*tmp.b+b*tmp.a);
    }
    c_Num operator +(c_Num tmp)
    {
        return c_Num(a+tmp.a,b+tmp.b);
    }
    c_Num operator -(c_Num tmp)
    {
       return c_Num(a-tmp.a,b-tmp.b);
    }
    void operator += (c_Num tmp)
    {
        a += tmp.a;
        b += tmp.b;
    }
    void operator -= (c_Num tmp)
    {
        a -= tmp.a;
        b -= tmp.b;
    }
    void operator *= (c_Num tmp)
    {
        c_Num t_o(a,b);
        a = t_o.a * tmp.a - t_o.b * tmp.b;
        b = t_o.a * tmp.b + t_o.b * tmp.a;
    }

    friend ostream &operator<<(ostream &s, c_Num ob);
};
ostream &operator<<(ostream &s, c_Num ob);

int main()
{
    c_Num a(10,-1), b(10,8);
    cout << a * b << "\n";

    return 0;
}

ostream &operator<< (ostream &s,c_Num ob)
{
    s << ob.a << "+" << ob.b << "i\n";
    return s;
}
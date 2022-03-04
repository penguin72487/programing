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

    long double a;
    long double b;
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
    friend ostream &operator<<(ostream &s, c_Num ob);
};
ostream &operator<< (ostream &s,c_Num ob)
{
    s << ob.a << "+" << ob.b << "i\n";
    return s;
}
int main()
{
    c_Num a(10,-1), b(10,8);
    cout << a * b << "\n";

    return 0;
}
#include<iostream>
#include<cmath>
#include<list>
#include<algorithm>
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
        b = 0;
    }
    c_Num()
    {
        a = 0;
        b = 0;
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
    c_Num& operator= (const c_Num& tmp)
    {
        a = tmp.a;
        b = tmp.b;
        return *this;
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
long long f_Pow(long long a, long long n);
c_Num *FFT(c_Num *&val,int n);
c_Num *iFFT(c_Num *&val,int n);

int main()
{
    string s_Val="54",s_Val2="87";
    //cin >> s_Val >> s_Val2;
    int t_N=s_Val.length()*s_Val2.length();
    int n = f_Pow(2,log2(t_N - 1) + 1);
    c_Num* val=new c_Num[n];
    c_Num *val2 = new c_Num[n];
    auto jt = val;
    for (auto it = s_Val.rbegin(); it != s_Val.rend(); ++it,++jt)
    {
        jt->a = *it - '0';
    }

    jt = val2;
    for (auto it = s_Val2.rbegin(); it != s_Val2.rend(); ++it,++jt)
    {
        jt->a = *it - '0';
    }

    for (int i = 0; i < n;++i)
    {
        cout << val[i] <<" ";
    }
    cout << "\n";
    for (int i = 0; i < n;++i)
    {
        cout << val2[i] <<" ";
    }
    cout << "\n";

    c_Num *t_Val = FFT(val, n);
    c_Num *t_Val2 = FFT(val2,n);
    for (int i = 0; i < n;++i)
    {
        cout << t_Val[i] <<" ";
    }
    cout << "\n";
    for (int i = 0; i < n;++i)
    {
        cout << t_Val2[i] <<" ";
    }
    cout << "\n";
    c_Num *ans = new c_Num[n];
    for (int i = 0; i < n;++i)
    {
        ans[i] = t_Val[i] * t_Val2[i];
    }
    delete[] val;
    delete[] val2;
    ans = iFFT(ans,n);
    int i_Ans=0;
    for (int i = 0; i < n;++i)
    {
        i_Ans += ans[i].a*(i+1);
    }
    cout << i_Ans << "\n";
    

    return 0;
}
ostream &operator<<(ostream &s, c_Num ob)
{
    s << ob.a << "+" << ob.b << "i";
    return s;
}
long long f_Pow(long long a, long long n)
{
    long long ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}
c_Num *FFT(c_Num* &val,int n)
{

    c_Num *end=val +n;
    if(n==1)
    {
        return val;
    }

    for (int i = 0; i < n;++i)
    {
        cout << val[i] <<" ";
    }
    cout << "\n";

    long double theta = (360 / n);

    int m = n >> 1;
    c_Num *Ye = new c_Num[m];
    c_Num *Yo=new c_Num[m];
    auto jt = Ye;

    for (auto it = val; it < end;it+=2)
    {
        *jt = *it;
    }
    jt = Yo;
    for (auto it = val + 1; it < end;it+=2)
    {
        *jt = *it;
    }
    for (int i = 0; i < m;++i)
    {
        cout << Ye[i] <<" ";
    }
    cout << "\n";
    for (int i = 0; i < m;++i)
    {
        cout << Yo[i] <<" ";
    }
    cout << "\n";
    Ye = FFT(Ye,m);
    Yo = FFT(Yo,m);
    for (int i = 0; i < n;++i)
    {
        val[i] = Ye[i] + c_Num(cos(theta * i), sin(theta * i))*Yo[i];
    }
    delete[] Ye;
    delete[] Yo;
    return val;
}
c_Num *iFFT(c_Num* &val,int n)
{
    c_Num *end=val +n;
    if(n==1)
    {
        return val;
    }

    long double theta = (360 / n);

    int m = n >> 1;
    c_Num *Ye = new c_Num[m];
    c_Num *Yo=new c_Num[m];
    auto jt = Ye;

    for (auto it = val; it < end;it+=2)
    {
        *jt = *it;
    }
    jt = Yo;
    for (auto it = val + 1; it < end;it+=2)
    {
        *jt = *it;
    }
    Ye = iFFT(Ye,m);
    Yo = iFFT(Yo,m);
    for (int i = 0; i < n;++i)
    {
        val[i] = Ye[i] + c_Num(cos(theta * i*-1), sin(theta * i*-1))*Yo[i];
    }
    delete[] Ye;
    delete[] Yo;
    return val;
}
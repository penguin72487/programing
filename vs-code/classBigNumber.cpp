#include<iostream>
#include<cmath>
#include<list>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;
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
    c_Num operator *(c_Num&& tmp)
    {
        return c_Num(a*tmp.a-b*tmp.b,a*tmp.b+b*tmp.a);
    }
    c_Num operator *(c_Num& tmp)
    {
        return c_Num(a*tmp.a-b*tmp.b,a*tmp.b+b*tmp.a);
    }
    c_Num operator *(int &tmp)
    {
        return c_Num(a*tmp);
    }
    c_Num operator /(int &tmp)
    {
        return c_Num(a/tmp,b/tmp);
    }
    c_Num operator +(c_Num &tmp)
    {
        return c_Num(a+tmp.a,b+tmp.b);
    }
    c_Num operator +(c_Num&& tmp)
    {
        return c_Num(a+tmp.a,b+tmp.b);
    }
    c_Num operator -(c_Num& tmp)
    {
       return c_Num(a-tmp.a,b-tmp.b);
    }
    c_Num operator -(c_Num&& tmp)
    {
       return c_Num(a-tmp.a,b-tmp.b);
    }
    void operator += (c_Num& tmp)
    {
        a += tmp.a;
        b += tmp.b;
    }
    void operator -= (c_Num& tmp)
    {
        a -= tmp.a;
        b -= tmp.b;
    }
    void operator *= (c_Num& tmp)
    {
        c_Num t_o(a,b);
        a = t_o.a * tmp.a - t_o.b * tmp.b;
        b = t_o.a * tmp.b + t_o.b * tmp.a;
    }
    void operator /= (int&& tmp)
    {
        
        a /=tmp;
        b /= tmp;
    }

    friend ostream &operator<<(ostream &s, c_Num& ob)
    {
        s << ob.a << "+" << ob.b << "i";
        return s;
    }
};
class BigNum{
public:
    BigNum(string& st_Val)
    {
        s_Val = st_Val;
    }
    BigNum(string&& st_Val)
    {
        s_Val = st_Val;
    }
    BigNum()
    {

    }
    string s_Val;
    //c_Num* val;
    friend ostream &operator<<(ostream &s, BigNum& ob)
    {
        s << ob.s_Val;
        return s;
    }
    friend ostream &operator<<(ostream &s, BigNum&& ob)
    {
        s << ob.s_Val;
        return s;
    }
    void operator=(string& tmp)
    {
      s_Val = tmp;
    }
    void operator=(string&& tmp)
    {
        s_Val = tmp;
    }
    BigNum operator *(BigNum& tt_Val2)
    {
        BigNum Big_ans;
        int t_N=s_Val.length()+tt_Val2.s_Val.length();
        int n = f_Pow(2,log2(t_N - 1) + 1);
        c_Num* val=new c_Num[n];
        c_Num *val2 = new c_Num[n];
        auto jt = val;
        for (auto it = s_Val.rbegin(); it != s_Val.rend(); ++it,++jt)
        {
            jt->a = *it - '0';
        }
        auto &s_Val2 = tt_Val2.s_Val;
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

        c_Num*&& t_Val = FFT(val, n);
        c_Num*&& t_Val2 = FFT(val2,n);
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
        vector<long long> i_Ans;
        for (int i = 0; i < n;++i)
        {
            cout << ans[i] <<" ";
        }
        cout << "\n";
        for (auto it = ans; it != ans + n;++it)
        {
            
            it->a += 0.5;
            it->a = static_cast<long long>(it->a);
            if(it->a==0)
            {
                break;
            }
            it->a /= n;
            i_Ans.push_back(it->a);
        }
        //   int mod10_16 = f_Pow(10, 16);
        for(auto it=i_Ans.begin();it!=i_Ans.end();it++) 	//統一進位 
        {
            if(*it>9)
            {
                auto itpl = ++it;
                --it;
                if(itpl==i_Ans.end())
                    i_Ans.push_back((*it/10));
                else
                    *(it+1)+=*it/10;
            *it%=10;
            }
        }
        reverse(i_Ans.begin(), i_Ans.end());
        auto it = i_Ans.begin();
        while(*it==0)
        {
            ++it;
        }
        stringstream ss;

        for (; it !=i_Ans.end();++it)
        {
            ss << *it;
        }
        ss << "\n";
        Big_ans=ss.str();
        delete[] ans;
        return Big_ans;
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
        /*
        for (int i = 0; i < n;++i)
        {
            cout << val[i] <<" ";
        }
        cout << "\n";
        */
        long double theta = (360.0 / n);

        int m = n >> 1;
        c_Num *Ye = new c_Num[m];
        c_Num *Yo=new c_Num[m];
        auto jt = Ye;

        for (auto it = val; it < end;it+=2)
        {
            *jt = *it;
            ++jt;
        }
        for (auto it = val + 1; it < end;it+=2)
        {
            *jt = *it;
            ++jt;
        }
        /*
        for (int i = 0; i < m;++i)
        {
            cout << Ye[i] <<" ";
        }
        cout << "\n";
        for (int i = 0; i < m;++i)
        {
            cout << Yo[i] <<" ";
        }
        cout << "\n";*/
        Ye = FFT(Ye,m);
        Yo = FFT(Yo,m);
        for (int i = 0; i < m;++i)
        {
            val[i] = Ye[i] + c_Num(cos(i_Rad(theta * i)), sin(i_Rad(theta * i)))*Yo[i];
            val[i+m] = Ye[i] - c_Num(cos(i_Rad(theta * i)), sin(i_Rad(theta * i)))*Yo[i];
        }
        for (int i = 0; i < n;++i)
        {
            cout << val[i] <<" ";
        }
        cout << "\n";
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

        long double theta = -(360.0 / n);

        int m = n >> 1;
        c_Num *Ye = new c_Num[m];
        c_Num *Yo=new c_Num[m];
        auto jt = Ye;

        for (auto it = val; it < end;it+=2)
        {
            *jt = *it;
            ++jt;
        }
        jt = Yo;
        for (auto it = val + 1; it < end;it+=2)
        {
            *jt = *it;
            ++jt;
        }
        Ye = iFFT(Ye,m);
        Yo = iFFT(Yo,m);
        for (int i = 0; i < m;++i)
        {
            val[i] = Ye[i] + c_Num(cos(i_Rad(theta * i)), sin(i_Rad(theta * i)))*Yo[i];
            //val[i] /= f_Pow(n,i);
            val[i+m] = Ye[i] - c_Num(cos(i_Rad(theta * i)), sin(i_Rad(theta * i)))*Yo[i];
            //val[i + m] /= f_Pow(n,i);
        }
        delete[] Ye;
        delete[] Yo;
        return val;
    }
    long double i_Rad(long double w )
    {
        return w*PI/180.0;
    }

};

int main()
{
    BigNum val("1234"),val2("1234");
    cout << val*val2 << "\n";

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <math.h>
using namespace std;
class bignumber{
    public:
        string s;
        vector<long long> val;
        bool sign=0;
        int digit=18;
        bignumber(){}
        bignumber(string &&t_s) : s(t_s){
            s_To_Vull();
        }
        
        void operator=(string &t_s) {
            s = t_s;
            s_To_Vull();
        }

        bignumber operator+(bignumber &b)
        {
            bignumber ans;
            if(val.size() >b.val.size())
            {
                auto it = val.begin();
                for (auto jt=b.val.begin();jt!=b.val.end();++jt,++it)
                {
                    ans.val.push_back(*it + *jt);
                }
                for (; it!=val.end();++it)
                {
                    ans.val.push_back(*it);
                }
            }
            else 
            {
                auto it = b.val.begin();
                for (auto jt=val.begin();jt!=val.end();++jt,++it)
                {
                    ans.val.push_back(*it + *jt);
                }
                for (; it!=b.val.end();++it)
                {
                    ans.val.push_back(*it);
                }
            }
            ans.unity_Carry();
            return ans;
        }
        bignumber operator-(bignumber &b)
        {
            bignumber ans;

            if(val.size() >b.val.size())
            {
                auto it = val.begin();
                for (auto jt=b.val.begin();jt!=b.val.end();++jt,++it)
                {
                    ans.val.push_back(*it - *jt);
                }
                for (; it!=val.end();++it)
                {
                    ans.val.push_back(*it);
                }
            }
            else 
            {
                auto it = b.val.begin();
                for (auto jt=val.begin();jt!=val.end();++jt,++it)
                {
                    ans.val.push_back(*jt-*it);
                }
                for (; it!=b.val.end();++it)
                {
                    ans.val.push_back(*it);
                }
            }
            ans.unity_Carry();
            return ans;
        }
        void unity_Carry(){
            long long max_Carry = q_Pow(10,digit);// 100000000000...
            long long mi_Carry = q_Pow(10, digit) - 1;//9999999999...
            for(auto it=val.begin();it!=val.end();++it)
            {
                if(*it>mi_Carry)
                {
                    if(next(it)!=val.end())
                    {
                        *next(it) += *it / max_Carry;
                        
                    }
                    else 
                    {
                        val.push_back(*it/max_Carry);
                    }
                    *it %= max_Carry;

                }
            }

        }
        void s_To_Vull()
        {
            

            auto it=s.rbegin();
            for (unsigned long long base=1; it != s.rend();base=1)
            {
                val.push_back(0);
                
                for (int i = 0; i < digit && it != s.rend(); ++i,++it,base=(base<<3)+(base<<1))
                {
                    val.back()+=(*it-'0')*base;
                }
            }
            val.shrink_to_fit();
        }
        friend istream& operator>>(istream& is, bignumber& b) {
            is>>b.s;
            b.s_To_Vull();
            return is;
        }

        friend ostream& operator<<(ostream& o,bignumber &b) {
            if(*b.val.begin()==0)
            {
                o << "0";
                return o;
            }
            if(b.sign==1)
            {
                o << '-';
            }
            cout << *b.val.rbegin();
            for(auto it=++(b.val.rbegin());it!=b.val.rend();++it)
            {
                for (int i = 0; i < b.digit-(int)log10(*it);++i)
                {
                    cout << "0";
                }
                    o << *it;
            }
            return o;
        }
        friend ostream& operator<<(ostream& o,bignumber b) {
            if(*b.val.begin()==0)
            {
                o << "0";
                return o;
            }
            if(b.sign==1)
            {
                o << '-';
            }
            cout << *b.val.rbegin();
            for(auto it=++(b.val.rbegin());it!=b.val.rend();++it)
            {
                if(*it!=0)
                {
                    int tmp = b.digit - log10(*it);
                    for (int i = 0; i < tmp;++i)
                    {
                        cout << "0";
                    }
                }
                else 
                {
                    
                    for (int i = 0,cash=b.digit-1; i < cash;++i)
                    {
                        cout << "0";
                    }
                }
                
                    o << *it;
            }
            return o;
        }
        long long q_Pow(long long a, long long n)
        {
            long long ans = 1;
            while (n) {
                if (n & 1)
                {
                    ans*= a;
                } 
                a *= a;
                n >>= 1;
            }
            return ans;

        }
};

int main()
{
    // bignumber a ("700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836");
    // bignumber b ("78387925687346587269786700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836700586330803670904226121762892396244129836");
    bignumber a;
    bignumber b;
    char c_Operator;
    cin >> a >>c_Operator>> b;
    //cout << a.s << "\n" << b.s << "\n";
    switch (c_Operator)
    {
        case '+':
            cout << a+b << "\n";
            break;
        case '-':
            cout << a - b << "\n";
            break;
        // case '*':
        //     cout << a * b << "\n";
        //     break;
        // case '/':
        //     cout << a / b << "\n";
        //     break;
    }

    return 0;
}
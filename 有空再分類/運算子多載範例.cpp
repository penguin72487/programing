#include<iostream>
using namespace std;

class bignum
{
    public:
    int num[1000];
    int digit;
    int negative;
    
    bignum()
    {
        digit = 1;
        for( int i = 0 ; i < 1000 ; i++ )
            num[i] = 0;
        negative = 0;
    }
    
    bignum( string s )
    {
        digit = s.length();
        for( int i = 0 ; i < s.length() ; i++ )
            num[i] = s[s.length()-i-1] - '0';
        for( int i = s.length() ; i < 1000 ; i++ )
            num[i] = 0;       
        negative = 0; 
    }
    
    bignum operator+( bignum x )
    {
        bignum ans;
        int max_digit = max( digit, x.digit );
        for( int i = 0 ; i < max_digit ; i++ )
        {
            ans.num[i] += num[i] + x.num[i];
            ans.num[i+1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = max_digit+1;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    bignum operator-( bignum x )
    {
        bignum ans;
        int max_digit = max( digit, x.digit );
        if( *this >= x )
        {
            for( int i = 0 ; i < max_digit ; i++ )
            {
                ans.num[i] = num[i] - x.num[i];
            }
            
        }
        else
        {
            for( int i = 0 ; i < max_digit ; i++ )
            {
                ans.num[i] = x.num[i] - num[i];
            }
            ans.negative = 1;
        }
        for( int i = 0 ; i < max_digit ; i++ )
        {
            if( ans.num[i] < 0 )
            {
                ans.num[i+1]--;
                ans.num[i] += 10;
            }
        }
        ans.digit = max_digit;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    bignum operator*( bignum x )
    {
        bignum ans;
        for( int i = 0 ; i < digit ; i++ )
            for( int j = 0 ; j < x.digit ; j++ )            
            ans.num[i+j] += num[i] * x.num[j];

        for( int i = 0 ; i < digit+x.digit+1 ; i++ )
        {
            ans.num[i+1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = digit+x.digit+1;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    bignum operator*( int x )
    {
        bignum ans;
        for( int i = 0 ; i < digit ; i++ )          
            ans.num[i] += num[i] * x;
        for( int i = 0 ; i < 998 ; i++ )
        {
            ans.num[i+1] += ans.num[i] / 10;
            ans.num[i] %= 10;
        }
        ans.digit = 999;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    bool operator>=( bignum x )
    {
        if( digit > x.digit )
            return true;
        if( digit < x.digit )
            return false;
        for( int i = digit ; i >= 0 ; i-- )
            if( num[i] > x.num[i] )
                return true;
            else if( num[i] < x.num[i] )
                return false;
        return true;
    }
    
    bignum operator/( bignum x )
    {
        bignum temp("0");
        bignum ans;
        for( int i = digit-1 ; i >= 0 ; i-- )
        {
            string tempstr = "";
            tempstr += (char)(num[i]+'0');
            temp = temp * 10 + bignum(tempstr);
            for( int j = 9 ; j > 0 ; j-- )
            {
                if( temp >= x*j )
                {
                    temp = temp - x*j;
                    ans.num[i] = j;
                    break;
                }
            }
        }
        ans.digit = digit;
        while( !ans.num[ans.digit] && ans.digit >= 0 )
            ans.digit--;
        if( ans.digit < 1 )
            ans.digit = 1;
        else
            ans.digit++;
        return ans;
    }
    
    void print()
    {
        if( negative )
            cout << '-';
        for( int i = digit-1 ; i >= 0 ; i-- )
            cout << num[i];
        cout << endl;
    }
};

int main()
{
    string a, b;
    char ope;
    while( cin >> a >> ope >> b )
    {
        bignum x(a), y(b);
        if( ope == '+' )
        {
            (x+y).print();
        }
        else if( ope == '-' )
        {
            (x-y).print();
        }
        else if( ope == '*' )
        {
            (x*y).print();
        }
        else if( ope == '/' )
        {
            (x/y).print();
        }
    }
    return 0;
}

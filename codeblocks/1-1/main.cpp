#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
struct str_let{
    char let;
    int num=0;

};
bool b_cmp  (str_let val,str_let val2)
    {

        if(val.num >val2.num)
        {
            return 1;
        }
        else if(val.num==val2.num)
        {
            if(val.let<val2.let)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
int main()
{
    string a;
    cin>>a;
    str_let str_a[28];
    for(int i=0;i<28;i++)
    {
        str_a[i].let='a'+i;

    }
    for(int i=0;i<a.length();i++)
    {
       // cout<<a[i]-'a'<<endl;
       int n= a[i]-'a';
       //cout<<n<<endl;
        str_a[n].num++;

    }
    sort(str_a,str_a+28,b_cmp);
    for(int i=0;i<28;i++)
    {
        if(str_a[i].num==0)
        {
            break;
        }
        cout<<str_a[i].let<<" "<<str_a[i].num<<endl;
    }
}

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
class s_Num{
    public:
    char c_Tmp;
    int i_Num;
    bool operator()(s_Num c1,s_Num c2)
    {
        if(c1.i_Num==c2.i_Num)
        {
            return (c1.c_Tmp>c2.c_Tmp);
        }
        else
        {
             return (c1.i_Num>c2.i_Num);

        }

    }
};
int main()
{
    string s;
    cin>>s;

    map<char,int> tmp;
    for(int i=0;i<s.length();i++)
    {
        if(tmp[s[i]]==NULL)
        {
            tmp[s[i]]=1;
        }
        else
        {
            ++tmp[s[i]];
        }
    }
    vector<s_Num> list;

    int n=tmp.size();
    list.resize(n);
    int i=0;
    for(auto it=tmp.begin();it!=tmp.end();++it)
    {
        list[i].c_Tmp=it->first;
        list[i].i_Num=it->second;
        ++i;
    }
    make_heap(list.begin,list.end(),s_Num());
    for(int j=0;j<n;++j)
    {
        list[0];
    }

}


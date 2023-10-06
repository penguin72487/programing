#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
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
    s_Num list[tmp.size()];
    int n=tmp.size();
    priority_queue<s_Num,s_Num()> que;
    {
    int i=0;
    for(auto it=tmp.begin();it!=tmp.end();++it)
    {
        list[i].c_Tmp=it->first;
        list[i].i_Num=it->second;
        ++i;
    }
    }
    for(int i=0;i<n;i++)
    {
      que.push(list[i]);
    }
    while(que.size())
    {

        cout<<que.top().c_Tmp<<" ";
        que.pop();
    }


}

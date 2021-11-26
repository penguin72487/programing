#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class node{
public :
    char oper;
    int data;
    node (char a,int b)
    {
        oper = a;
        b = data;
    }
};
long long getans(vector<vector<pair<char,int>>> &list,vector<int> s,int index)
{
    long long ans=0;
    if(index==8)
    {
        return 1;
    }
    //bool flag = 0;
    for (int i = 1; i < list.size();++i)
    {
        s.push_back(i);
        for (auto it = list[index].begin(); it != list[index].end();++it)
        {
            if(it->first=='<')
            {
                if(s[it->second]<s.back())
                {
                    //flag = 1;
                    ans += getans(list,s,index+1);
                }
            }

        }
        s.pop_back();
    }
        return ans;
}
long long q_Pew(int a,int n)
{
    long long ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans *= a;
        }
        a*= a;
        n >>= 1;
    }
    return ans;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pair<char,int>>> list(n+1);
    for (int i = 0; i < m; ++i)
    {
        int a,b;
        char c;
        cin >> a >> c >> b;
        if(a>b)
        {
            list[a].push_back(make_pair(c,b));
        }
        else
        {
            if(c=='<')
            {
                c = '>';
            }
            else
            {
                c = '<';
            }
            list[b].push_back(make_pair(c,a));
        }
    }
    long long i_ans = 0;
    long long d = q_Pew(n,n);
    for (int i = 1; i <=n;++i)
    {
        vector<int> tmp;
        tmp.push_back(i);
        i_ans += getans(list,tmp,2);
    }
    long double ans = i_ans / d;
    cout << ans << "\n";

    /*
    for (auto it = list.begin(); it != list.end();++it)
    {
        for (auto jt = it->begin(); jt != it->end();++jt)
        {
            cout << jt->first << " " << jt->second<<" ";
        }
        cout << "\n";
    }
    */

}
#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    int count_C = 0;
    int count_S = 0;
    int count=0;
    
    for(auto it=s.begin(); it!=s.end();++it)
    {
        if(*it=='?')
        {
            ++count_C;
        }
        else if(*it=='*')
        {
            ++count_S;
        }
        else {
            ++count;
        }
    }
    if(n<(count-count_C-count_S))
    {
        cout << "Impossible\n";
        return 0;
    }
    else if(n>count&&(!count_S)){
        cout << "Impossible\n";
        return 0;
    }
    string ans;
    if(n<count)
    {
        //int tmp = count - n;
        for(auto it=s.begin(); it!=s.end()&&count!=n;++it)
        {
            if(*next(it)=='?'||*next(it)=='*')
            {
                ++it;
                --count;
            }
            else{
                ans.push_back(*it);
            }
            if(count==n)
            {
                ++it;
                for (; it != s.end();++it)
                {
                    if(*it=='?'||*it=='*')
                    {
                        //++it;
                    }
                    else {
                        ans.push_back(*it);
                    }
                    
                }    
                    
                    break;
            }
        }
    }
    else if(n==count)
    {
        for (auto it = s.begin(); it != s.end();++it)
        {
            if(*it=='?'||*it=='*')
            {

            }
            else {
                    ans.push_back(*it);
            }
        }
    }
    else if(n>count)
    {
        for(auto it=s.begin(); it!=s.end();++it)
        {
            if(*next(it)=='?')
            {
                    ++it;
            }
            else if(*next(it)=='*')
            {
                    for (int i = count; i <= n;++i)
                    {
                        ans.push_back(*it);
                    }
                    ++it;
            }
            else {
                ans.push_back(*it);
            }
        }
    }
    cout << ans;

    return 0;
}
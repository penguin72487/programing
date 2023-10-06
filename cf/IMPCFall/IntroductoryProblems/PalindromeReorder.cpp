#include<iostream>
#include<deque>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    cin >> s;
    int count[26]={0};
    for(auto it=s.begin(); it!=s.end(); ++it){
        ++count[*it - 'A'];
    }
    int odd = 0;
    int odd_Letter=0;
    int even = 0;
    for(int i= 0; i<26;++i)
    {
        if(count[i]&1)
        {
            ++odd;
            odd_Letter=i;
        }
        else {
            ++even;
        }
    }
    deque<char> ans;
    if(odd>1){
        cout << "NO SOLUTION\n";
    }
    else if(odd==1){
        ans.push_back(char(odd_Letter+'A'));
        --count[odd_Letter];
        for(int i=0; i<26;++i)
        {
            for (int j = 0; j < (count[i]>>1);++j)
            {
                 ans.push_back(i+'A');
                 ans.push_front(i + 'A');
            }
        }
        for(auto i=ans.begin(); i!=ans.end();++i){
            cout << *i;
        }
        cout<<"\n";
    }
    else{
        for(int i=0; i<26;++i)
        {
            for (int j = 0; j < (count[i]>>1);++j)
            {
                 ans.push_back(i+'A');
                 ans.push_front(i + 'A');
            }
        }
        for(auto i=ans.begin(); i!=ans.end();++i){
            cout << *i;
        }
        cout<<"\n";
    }
    return 0;
}
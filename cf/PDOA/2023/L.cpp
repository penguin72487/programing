#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    map<char, int> ci_Score;
    ci_Score['r'] = 3;
    ci_Score['g'] = 2;
    ci_Score['w'] = 1;
    ci_Score['b'] = 0;
    string p1="Deft",p2="Faker";
    while(t--){
        string pt;
        cin >> pt;
        if(pt!=p1)
        {
            swap(p1,p2);
        }
        string flag;
        int score[2]={};
        cin>>flag;
        deque<int> dq;
        for(auto& c:flag)
        {
            dq.push_back(ci_Score[c]);
        }
        for(int i=0;i<flag.size();++i)
        {
            int tmp = dq.front();
            dq.pop_front();
            score[0]+=tmp;
        }
        if(score[0]>score[1])
        {
            cout<<p1<<"\n";
        }
        else 
        {
            cout<<p2<<"\n";
        }

    }
    return 0;
}
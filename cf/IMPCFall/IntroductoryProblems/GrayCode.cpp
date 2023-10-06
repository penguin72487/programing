#include<iostream>
#include<deque>
#include<vector>
using namespace std;
void gray(int now,int n,deque<bool> s){

    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<deque<bool>> s(2);
    vector<deque<bool>> tmp;
    s[0].push_back(0);
    s[1].push_back(1);
    tmp = s;
    for(int i = 0; i < n; ++i){
        s.resize(s.size()<<1);
        for(auto it = s.begin(),jt=s.rbegin().base(); it <jt; ++it,--jt){
            it->push_back(0);
        }
    }

    return 0;
}
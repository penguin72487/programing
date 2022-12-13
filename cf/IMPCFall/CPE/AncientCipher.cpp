#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s,t;
    while(cin>>s)
    {
        cin >> t;
        vector<int> v_S(26,0);
        vector<int> v_T(26,0);
        for(auto it=s.begin();it!=s.end();++it)
        {
            ++v_S[*it - 'A'];
        }
        for(auto it=t.begin();it!=t.end();++it)
        {
            ++v_T[*it - 'A'];
        }
        sort(v_S.begin(), v_S.end());
        sort(v_T.begin(), v_T.end());
        if(v_S==v_T)
        {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<char> a;
    for(auto it=s.begin(); it!=s.end(); ++it){
        a.push_back(*it);
    }
    sort(s.begin(), s.end());
    vector<string> ans;
    do    {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << ans.size() << "\n";
    for(auto it=ans.begin(); it!=ans.end(); ++it){
        cout << *it << "\n";
    }

    return 0;
}
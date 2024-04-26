#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        vector<int> diff;
        if(s.size()!=goal.size()) return false;
        if(s==goal){
            unordered_set<char> st;
            for(char c:s){
                if(st.count(c)) return true;
                st.insert(c);
            }
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]) diff.push_back(i);
        }
        if(diff.size()!=2) return false;
        return s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    
    return 0;
}
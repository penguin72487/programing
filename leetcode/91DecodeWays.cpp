#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            if(i>1 && s[i-2]!='0' && stoi(s.substr(i-2,2))<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    cout<<s.numDecodings("12")<<endl;
    
    return 0;
}
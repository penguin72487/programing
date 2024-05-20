#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n][5];
        fill(dp[0],dp[0]+5,1);
        for(int i=1;i<n;i++){
            dp[i][0]=1;
            for(int j=1;j<5;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return accumulate(dp[n-1],dp[n-1]+5,0);

        
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    cout << s.countVowelStrings(2) << endl;
    cout << s.countVowelStrings(33) << endl;
    return 0;
}
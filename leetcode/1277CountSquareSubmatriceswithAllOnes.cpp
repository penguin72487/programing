#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        map<int, int> mp_Mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if(i==0 || j==0){
                        mp_Mat[i*m+j]=1;
                    }
                    else{
                        mp_Mat[i*m+j]=min({mp_Mat[(i-1)*m+j],mp_Mat[i*m+j-1],mp_Mat[(i-1)*m+j-1]})+1;
                    }
                }
            }
        }
        int ans=0;
        for(auto it:mp_Mat){
            ans+=it.second;
        }
        return ans;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<vector<int>> matrix{{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout << s.countSquares(matrix) << endl;
    return 0;
}
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return log2(left^right) ? 0 : left & right;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    cout<<s.rangeBitwiseAnd(5,7)<<'\n';
    
    return 0;
}
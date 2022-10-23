#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
        {
            return 1;
        }
        else if(n==4)
        {
            return 0;
        }
        long long sum = 0;
        while(n){
            sum += pow2(n%10,n%10);
            n/= 10;
        }
        return isHappy(sum);
    }
    long long pow2(int &&a,int &&b) {
        return a * b;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout << s.isHappy(2);
}
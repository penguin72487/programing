#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        --m;
        --n;
        int k = m + n + 1;
        long long o_sum = 1;
        for (int i = 2; i < min(m, n)+1;++i)
        {
            o_sum *= i;
        }
        long long sum = 1;
        for (int i = max(m, n); i < k;++i)
        {
            sum *= i;
            if(sum % o_sum==0&&o_sum)
            {
                sum/= o_sum;
                o_sum = 0;
            }
        }
        
        return int(sum);
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout << s.uniquePaths(3,4);
    return 0;
}
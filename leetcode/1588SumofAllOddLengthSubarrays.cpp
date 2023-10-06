#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        partial_sum(arr.begin(), arr.end(), arr.begin());
        arr.insert(arr.begin(), 0);
        for (int num = 1;num<=n;num+=2)
        {
            for (int i = num; i <=n;++i)
            {
                ans+=arr[i]-arr[i-num];
            }
        }
        return ans;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {1,4,2,5,3};
    cout << s.sumOddLengthSubarrays(num);
}
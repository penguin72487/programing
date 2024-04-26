#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int i_Op = 0;
        int i_Ed= sum;
        while (i_Op < i_Ed)
        {
            int mid = (i_Op + i_Ed) / 2;
            if (couldDo(weights, days, mid))
            {
                i_Ed = mid;
            }
            else
            {
                i_Op = mid + 1;
            }
        }
        return i_Op;
    }
    bool couldDo(vector<int>& weights, int days, int packet)
    {
        int sum = 0;
        for (int i = 0, n = weights.size(); i < n; ++i)
        {
            if(weights[i]>packet)
                return false;
            if (sum + weights[i] > packet)
            {
                sum = 0;
                --days;
            }
            sum += weights[i];
        }
        return days >0;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {1,2,3,1,1};
    int d = 4;
    cout<<s.shipWithinDays(num,d);
    return 0;
}
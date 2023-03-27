#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int i_op = 1;
        long long i_ed = 1e14;
        sort(time.begin(),time.end());
        while(i_op < i_ed)
        {
            long long i_mid = (i_op + i_ed)/2;
            if(fit(time,totalTrips,i_mid))
            {
                i_ed = i_mid;
            }
            else
            {
                i_op = i_mid + 1;
            }
        }
        return i_op;
    }
    bool fit(vector<int>& time, int totalTrips, long long timeLimit)
    {
        long long int trips = 0;
        for(auto i:time)
        {
            trips += timeLimit/i;
            if(trips >= totalTrips)
            {
            return trips >= totalTrips;
            }
        }
        return trips >= totalTrips;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    int totalTrips = 5;
    vector<int> num = {1,2,3};
    cout<<s.minimumTime(num,totalTrips)<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        adjacent_difference(prices.begin(),prices.end(),prices.begin());
        vector<int> a;
        int sum=0;
        for(int i=1;i<prices.size();++i)
        {
            sum+=prices[i];
            if(sum<0)
            {
                a.push_back(sum-prices[i]);
                sum=0;
            }
        }
        if(sum>=0)
        a.push_back(sum);
        sort(a.begin(),a.end());
        if(a.size()<=1)
        {
            return a.back();
        }
        else
        {
            return a.back()+a[a.size()-2];
        }
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    cout<<s.maxProfit(prices);
    return 0;
}
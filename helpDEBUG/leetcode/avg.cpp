class Solution {
public:
    double average(vector<int>& salary) {
        long long sum=0;
        for(auto it=salary.begin();it!=salary.end();++it)
        {
            sum+=*it;
        }
        return (sum-*max_element(salary.begin(),salary.end())-*min_element(salary.begin(),salary.end()));
    }
};
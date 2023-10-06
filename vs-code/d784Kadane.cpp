#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int vi_Kadane(vector<int> &v_Arr);
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n;++i)
    {
        int m;
        cin >> m;
        vector<int> v_Arr;
        while(m--)
        {
            int tmp;
            cin >> tmp;
            v_Arr.push_back(tmp);
        }
        cout << vi_Kadane(v_Arr)<<"\n";
    }
}
int vi_Kadane(vector<int> &v_Arr)
{
    int pre_Sum = 0;
    int ans = -2147483648;
    for(auto it=v_Arr.begin();it!=v_Arr.end();++it)
    {
        pre_Sum = max(*it, *it + pre_Sum);
            ans =max(ans,pre_Sum);
    }
    return ans;
}
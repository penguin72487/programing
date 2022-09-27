#include <iostream>
#include <algorithm>
#include <deque>
#include<vector>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        vector<int> programmer;
        for (int i = 0, tmp; i < n; ++i)
        {
            cin >> tmp;
            programmer.push_back(tmp);
        }
        sort(programmer.begin(), programmer.end());
        deque<int> temp_Ans;
        while (programmer.size())
        {
            temp_Ans.push_back(programmer.back());
            programmer.pop_back();
            while (temp_Ans.size() * temp_Ans.back() < m && programmer.size())
            {
                temp_Ans.push_back(programmer.back());
                programmer.pop_back();
            }
            if (programmer.empty() && temp_Ans.size() * temp_Ans.back() < m)
            {

            }
            else
            {
                ++ans;
            }



            temp_Ans.clear();

        }
        cout << ans << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){

    cin.tie(0)->sync_with_stdio(0);

    int num;
    vector<int> a;
    while (cin >> num)
    {
        a.push_back(num);
    }
    int N = (int) a.size();
    int dp[N+1];
    vector<int> v;
    dp[0] = 1;
    v.push_back(a[0]);
    int L = 1; //LIS length
    for (int i=1; i<N; i++){
        if (a[i] > v.back()){
            v.push_back(a[i]);
            L++;
            dp[i] = L;
        } else {
            auto it = lower_bound(v.begin(), v.end(), a[i]);
            *it = a[i];
            dp[i] = (int) (it - v.begin() + 1);
        }
    }
    cout << L << "\n-\n";
    vector<int> ans;
    for (int i=N-1; i>=0; i--){
        if (dp[i] == L){
            ans.push_back(a[i]);
            L--;
        }
    }
    for (auto it = ans.rbegin(); it != ans.rend();++it)
    {
        cout << *it << "\n";
    }
}
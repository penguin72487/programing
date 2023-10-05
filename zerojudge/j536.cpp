#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& i:a)
    {
        cin >> i;
    }
    int max_Ind = max_element(a.begin(), a.end())-a.begin();
    partial_sum(a.begin(), a.end(), a.begin());
    
    a.insert(a.begin(), 0);
    int op = max(max_Ind - k/2-1, 0);
    int ed = min(max_Ind + k/2+1-(max_Ind - k/2), n);
    
    cout << a[ed] - a[op]<<" "<<*a.rbegin() -a[ed] + a[op]<<"\n";


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    forward_list<int> a(3);
    for(auto& it:a)
    {
        cin >> it;
    }
    cout << accumulate(a.begin(), a.end(), 0)<<"\n";

    return 0;
}
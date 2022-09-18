#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);
    int t; cin >> t;
    while(t--){
        int ans = 0;
        int n; cin >> n;
        ++n;
        vector <int> child(n);
        for(int i = 2; i < n; i++){
            int tp;
            cin >> tp;
            ++child[tp];
        }
        sort(child.begin(), child.end());
        int Infected = 0;
        //int increse=1;
        for (auto it = upper_bound(child.begin(), child.end(), Infected); it != child.end();it = upper_bound(child.begin(), child.end(), Infected))
        {
            ans += child.end()-it;
            //++increse;
            Infected += child.end() - it+1; //+increse;
        }
        cout << ans+1 << "\n";
    }

return 0;
}
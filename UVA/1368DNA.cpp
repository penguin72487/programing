#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> vs(n);
        for(int i=0; i<n;++i)
        {
            cin >> vs[i];
        }
        string ans;
        long long sum = 0;
        for(int i=0; i<m;++i)
        {
            vector<int> cha(26, 0);
            for(int j=0; j<n;++j)
            {
                ++cha[vs[j][i] - 'A'];
            }
            ans.push_back(max_element(cha.begin(),cha.end())-cha.begin()+'A');
            sum += accumulate(cha.begin(), cha.end(), 0ll) - *max_element(cha.begin(), cha.end());
        }
        cout << ans << "\n"<<sum<<"\n";

    }
    return 0;
}
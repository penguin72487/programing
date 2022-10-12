#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int w[k];
        map<int, int> count_W;
        for(int i=0; i<k; i++)
        {
            cin>>w[i];
            count_W[w[i]] = 0;
        }
        for(int i=0; i<k; i++)
        {
            ++count_W[w[i]];
        }
        sort(a,a+n);
        
        reverse(a,a+n);
        auto it_A = a;
        //sort(w,w+k);x
        long long ans = 0;
        for(auto it=count_W.begin(); it!=count_W.end();++it)
        {
            //int m=it->first;
            for(int i=0; i<it->second;++i)
            {
                ans += *it_A;
                ++it_A;
            }
            //it_A=a;
            for(int i=0; i<it->second;++i)
            {
                it_A += (it->first - 2);
                ans += *it_A;
                ++it_A;
            }
        }
        cout<<ans << "\n";
    }
    return 0;
}
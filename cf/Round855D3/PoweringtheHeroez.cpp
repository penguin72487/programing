#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue<int> pq;
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            if(tmp>0)
            pq.push(tmp);
            else if(tmp==0){
                if(pq.empty())
                {
                    continue;
                }
                ans+=pq.top();
                pq.pop();
            }
        }
        cout<<ans<<"\n";
    } 
    return 0;
}
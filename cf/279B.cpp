#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,t;
    cin >> n>>t;
    deque<int> line;
    int ans=0;// max
    int sum=0;
    for(int i=0,in_Cash;i<n;++i){
        cin >> in_Cash;
        if(sum+in_Cash<=t)
        {
            line.push_back(in_Cash);
            sum+=in_Cash;
            ans = max(ans, (int)line.size());
        }
        else 
        {
            line.push_back(in_Cash);
            sum+=in_Cash;
            while(sum>t)
            {
                sum-=line.front();
                line.pop_front();
            }
            ans = max(ans, (int)line.size());

        }

    }
    cout << ans << "\n";

    return 0;
}
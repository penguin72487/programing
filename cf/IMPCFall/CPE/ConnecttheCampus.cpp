#include<iostream>
#include<unordered_map>
#include<queue>
#include<tuple>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    while(cin>>n&&n!=0)
    {

        priority_queue<tuple<int,int,int>> STL;
        vector<int> passed(n,0);
        vector<pair<int, int>> v_II;
        for(int i=0,a,b;i<n;++i)
        {
            cin >> a >> b;
            v_II.push_back(make_pair(a, b));
        }
        int m;
        cin >> m;
        for(int i=0,a,b;i<m;++i)
        {
            cin >> a >> b;
            passed[a] = 1;
            passed[b] = 1;
        }
        
    }
    return 0;
}
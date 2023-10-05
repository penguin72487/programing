#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int v[2][2];
        cin>>v[0][0]>>v[0][1]>>v[1][0]>>v[1][1];
        vector<int> v1;
        v1.push_back(v[0][0]+v[0][1]+v[1][0]+v[1][1]);
        v1.push_back(v[0][0]*v[0][1]*2+v[1][0]*v[1][1]*2);
        v1.push_back(v[0][0]*v[1][0]*2+v[0][1]*v[1][1]*2);
        v1.push_back(v[0][0]+v[1][1]*(v[0][1]+v[1][0])*2);
        v1.push_back(v[0][1]+v[1][0]*(v[0][0]+v[1][1])*2);
        v1.push_back(v[1][0]+v[0][1]*(v[0][0]+v[1][1])*2);
        v1.push_back(v[1][1]+v[0][0]*(v[0][1]+v[1][0])*2);
        v1.push_back(v[0][0]*(v[0][1]+v[1][0])+v[0][1]*(v[0][0]+v[1][1])+v[1][1]*(v[0][1]+v[1][0])+v[1][0]*(v[0][0]+v[1][1]));
        cout<<*max_element(v1.begin(), v1.end())<<"\n";
    }
    return 0;
}
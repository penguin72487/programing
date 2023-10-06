#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> passenger(n);
        vector<tuple<char,int>> vpci_Op(q);
        for(auto& [p,c]:vpci_Op)
        {
            cin >> p >> c;
        }
        bool flag = 0;
        int count = 0;
        for(auto& [p,c]:vpci_Op)
        {
            if(c>n)
            {
                flag = 1;
                break;
            }
            if(p=='+')
            {
                if(count>=m||passenger[c-1]!=0)
                {
                    flag = 1;
                    break;
                }
                else 
                {
                    ++count;
                    passenger[c - 1]++;
                }
            }
            else 
            {
                if(count<=0||passenger[c-1]!=1)
                {
                    flag = 1;
                    break;
                }
                else 
                {
                    --count;
                    passenger[c - 1]++;
                }
            }
        }
        if(flag)
        {
            cout << "invalid\n";
        }
        else 
        {
            cout << "valid\n";
        }
    }
    return 0;
}
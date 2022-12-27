#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        unordered_map<int,string> is_Map;
        set<int> up;
        set<int> down;
        int n;
        cin >> n;
        string s,t;
        int a, b;
        for(int i = 0; i < n;++i)
        {
            cin >> s >> a >> b;
            is_Map[a] = s;
            is_Map[b] = s;
            down.insert(a);
            up.insert(b);
        }
        cin >> n;
        for(int i = 0; i < n;++i)
        {
            cin >> a;
            if(a<*down.begin()||a>*up.rbegin())
            {
                cout << "UNDETERMINED\n";
            }
            else {
                if(a>*down.rbegin())
                {
                    s = is_Map[*down.rbegin()];
                }
                else {
                    s = is_Map[*(--down.upper_bound(a))];
                }
                if(a<*up.begin()){
                    t = is_Map[*up.begin()];
                }
                {
                    t = is_Map[*(up.lower_bound(a))];
                }
                

                if(s==t)
                {
                    cout << s << "\n";
                }
                else {
                    cout << "UNDETERMINED\n";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
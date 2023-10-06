#include<iostream>
#include <algorithm>
#include<set>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        multiset<char> s;
        s.insert('a');
        multiset<char, greater<char>> t;
        t.insert('a');
        int d, k;
        string tmp;
        for(int i=0; i<q; i++){
            cin >> d >> k >> tmp;
            if(d==1)
            {
                for (int j = 0; j < k;++j)
                {
                    for(auto it=tmp.begin(); it!=tmp.end(); ++it){
                        s.insert(*it);
                    }
                }
            }
            else {
                for (int j = 0; j < k;++j)
                {
                    for(auto it=tmp.begin(); it!=tmp.end(); ++it){
                        t.insert(*it);
                    }
                }
            }
            if(lexicographical_compare(s.begin(),s.end(),t.begin(),t.end()))
            {
                cout << "YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        // if(lexicographical_compare(s.begin(),s.end(),t.begin(),t.end()))
        // {
        //     cout << "YES\n";
        // }
        // else {
        //     cout<<"NO\n";
        // }

    }
    return 0;
}
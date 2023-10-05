#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, char>> vpii(26, {0, 'A'});
    for (int i = 0; i < 26;++i)
    {
        vpii[i].second += i;
    }
    cin.get();
    for (int i = 0; i < n;++i)
    {
        string s;
        getline(cin, s);
        //cin.get();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(auto& it:s)
        {
            if(it<= 'z' && it>='a')
            {
                vpii[it-'a'].first++;
            }
        }
    }
    sort(vpii.begin(), vpii.end(), [](auto& a, auto& b)->bool {
        if(a.first==b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    for(auto i:vpii)
    {
        if(i.first==0)
        {
            break;
        }
        cout << i.second << " " << i.first << "\n";
        
    }
        return 0;
}
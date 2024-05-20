#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mccs, mcct;
        for (int i = 0; i < 26;++i)
        {
            mccs['a' + i] = 'a' + i;
            mcct['a' + i] = 'a' + i;

        }

        int n = s.size();
        for (int i = 0; i < n;++i)
        {
            mccs[s[i]] = t[i];
            mcct[t[i]] = s[i];
        }
        string ss=s, tt=t;
        for (int i = 0; i < n;++i)
        {
            ss[i] = mcct[ss[i]];
            tt[i] = mccs[tt[i]];
        }
        return ss == t && tt == s;
        
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    Solution s;
    cout << s.isIsomorphic("badc", "baba") << endl;


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
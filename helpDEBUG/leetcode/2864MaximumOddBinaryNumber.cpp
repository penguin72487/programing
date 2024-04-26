#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        char minOdd = '9';
        for (char c : s) {
            if ((c)&1){
                minOdd = min(minOdd, c);
            }
        }
        sort(s.begin(), s.end(), greater<char>());
        auto it= upper_bound(s.begin(), s.end(), minOdd, greater<char>());
        s.erase(--it);
        

        return s+minOdd;
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
    cout << s.maximumOddBinaryNumber("001") << endl;
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
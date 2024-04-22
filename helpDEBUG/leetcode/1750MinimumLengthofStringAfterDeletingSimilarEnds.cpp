#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        deque<char> dc;
        for(auto c:s) dc.push_back(c);
        while(dc.size()>1 && dc.front()==dc.back()){
            char c = dc.front();
            while(!dc.empty() && dc.front()==c) dc.pop_front();
            while(!dc.empty() && dc.back()==c) dc.pop_back();
        }
        return dc.size();      
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
    cout<<s.minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb")<<endl;

    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
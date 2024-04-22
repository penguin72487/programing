#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        int res=0;
        string temp;
        while(ss>>temp)
        {
            res=temp.size();
        }
        return res;
        
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
    string str="Hello World";
    cout<<s.lengthOfLastWord(str)<<endl;
    
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << double (duration.count())/1000000.0 << " ms.\n";
    #endif

    return 0;
}
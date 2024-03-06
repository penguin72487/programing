#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int res=0;
        int maxres=0;
        for(int i=0,j=tokens.size()-1;i<=j;){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                res++;
            }
            else if(res>0){
                power+=tokens[j];
                j--;
                res--;
            }
            else{
                break;
            }
            maxres=max(maxres,res);
        }
        return maxres;
        
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
    vector<int> tokens={100,200,300,400};
    int power=200;
    cout<<s.bagOfTokensScore(tokens,power);
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
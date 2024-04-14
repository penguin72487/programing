#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int deal_By_Mod(int mod_Odd, int mod_Even)
{
    if(mod_Odd>mod_Even) 
    {
        return 1;
    }
    else if(mod_Odd<mod_Even)
    {
        mod_Even-=mod_Odd;
        return mod_Even%3;
    }
    else
    {
        return 0;
    }
}
int deal_By_Pair(int mod_Odd, int mod_Even)
{
    if(mod_Odd>mod_Even) 
    {
        return 1;
    }
    else if(mod_Odd<mod_Even)
    {
        mod_Even-=mod_Odd;
        return mod_Even%3;
    }
    else
    {
        return 0;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int mod_Odd=0, mod_Even=0;
        for(auto &x: a){
            cin >> x;
            if(x%3==1) mod_Odd++;
            else if(x%3==2) mod_Even++;
        }
        cout<<

        
        
    }
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
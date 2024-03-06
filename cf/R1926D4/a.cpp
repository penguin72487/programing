#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif

    while(n--)
    {
        string s;
        cin>>s;
        int a, b;
        a = b = 0;
        for(auto i:s)
        {
            if(i=='A')
                a++;
            else
                b++;
        }
        cout<<((a<b)?("B"):("A"))<<endl;
    }


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
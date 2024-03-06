#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    while (t--)
    {
        int n;
        cin>>n;
        string a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='1')
                {
                    if(a[i][j+1]=='0')
                    {
                        cout << "TRIANGLE\n";
                        goto end;
                    }
                    else if(a[i+1][j]=='0')
                    {
                        cout << "TRIANGLE\n";
                        goto end;
                    }
                    else {
                        cout << "SQUARE\n";
                        goto end;
                    }
                }
            }
        }
        end:;
    }
    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
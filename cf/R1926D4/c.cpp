#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int sum_digits(int n)
{
    int sum = 0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    vector<int> v(200001);
    v[0] = 0;
    for(int i=1;i<200001;i++)
    {
        v[i] = v[i-1]+ sum_digits(i);
    }
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
        cout<<v[n]<<endl;
    }
    
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
void mergeSort(int* l, int* r) {
    if(l<r-1)
    {
        auto m = l+(r-l)/2;
        auto il=m, ir=m;
        auto lm = il - 1;
        auto rm=r-1;
        mergeSort(l,il);
        mergeSort(il,r);
        for (auto i = l, j = ir; i < j; i++)
        {
            if(*i>*j)
            {
                swap(*i, *j);
            }
        }
    
    }
    return;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n = 5;
    int v[] = {1, 3, 7, 2, 4};//0
#ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    mergeSort(v, v+n);
    for(auto i:v)
    {
        cout << i << " ";
    }
    cout << endl;

    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
long double totle_APR(long double S0, long double ratio, long double Fee, long double slip, long double num_compounds) {
    for(int i=0;i<num_compounds;++i) {
        S0 = S0 * (1 + ratio * (1 - slip) / num_compounds) - Fee;
    }
    return S0;
}
tuple<int,long double> ternary_search(long double S0, long double ratio, long double Fee, long double slip, int L, int R) {
    while (R - L > 2) {
        int m1 = L + (R - L) / 3;
        int m2 = R - (R - L) / 3;
        long double f1 = totle_APR(S0, ratio, Fee, slip, m1);
        long double f2 = totle_APR(S0, ratio, Fee, slip, m2);
        if (f1 < f2)
            L = m1;
        else
            R = m2;
    }
    // 在最後的範圍中找最大值
    long double max_value = totle_APR(S0, ratio, Fee, slip, L);
    int best = L;
    for (int i = L + 1; i <= R; i++) {
        long double value = totle_APR(S0, ratio, Fee, slip, i);
        if (value > max_value) {
            max_value = value;
            best = i;
        }
    }
    return {best, max_value};
}
int main() {
    // long double S0 = 712; // atom 41.5 ada 1735 sui 220
    // long double ratio = 54.73 / 100.0; // 16.99 3.03 69
    // long double Fee = 0.06; //  0.06 0.2 0.06
    // long double slip = 0 / 100.0; // 0 0 1.16

    vector<tuple<string, long double, long double, long double, long double> > v;
    v.push_back(make_tuple("ATOM", 41.5, 16.99/100.0, 0.06, 0));
    v.push_back(make_tuple("ADA", 1735, 3.03/100.0, 0.2, 0));
    v.push_back(make_tuple("SUI Scallop", 2000.0, 36.0/100.0, 0.04, 0/100));
    v.push_back(make_tuple("SUI Bucket", 330, 30.0/100.0, 0.06, 0));
    v.push_back(make_tuple("SUI Navi", 1975, 6.83/100.0, 0.1, 0));
    int total_seconds = 365 * 24 * 60 * 60; // 一年的總秒數

    for(auto& [name, S0, ratio, Fee, slip] : v) {
        // long double max_value = S0;
        // int optimal_frequency = total_seconds;
        auto [optimal_frequency, max_value] = ternary_search(S0, ratio/total_seconds, Fee, slip, 1, total_seconds);

        cout << fixed << setprecision(9);
        cout << name << endl;
        cout << "Optimal frequency: " << optimal_frequency << " seconds ";
        // cout << "Optimal frequency: " << optimal_frequency / 60 << " minutes" << endl;
        cout << (long double)optimal_frequency /3600.0 << " hours ";
        cout << (long double)optimal_frequency / 60.0 / 60.0 / 24.0 << " days" << endl;
        cout << "Initial value: " << S0<<" ";
        cout << "Max value: " << max_value << endl;
        cout << "Original APY: " << ratio * 100.0 << "% ";
        cout << "APY: " << (max_value - S0) / S0 * 100 << "% ";
        cout << "Max APY: " << exp(ratio) * 100.0 - 100.0 << "%" << endl
             << endl;
        // atom 91.25 ada 121.67 sui 10.43
    }

    return 0;
}

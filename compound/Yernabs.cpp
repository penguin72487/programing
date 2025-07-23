#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
long double totle_APR(long double S0, long double ratio, long double Fee, long double slip, int total_seconds, long double A) {
    long double r = ratio/total_seconds;// second ratio
    long double time = total_seconds;
    long double p = S0;
    if(A/(p*r) > time) {
        return -1.0 * A / (p * r);
    }
    while (time >= A/(p*r)) {
        time-= A/(p*r);
        p=p+A-Fee;
    }
    return p + p * r * time - Fee *((time)/(A / (p * r)));
}
int main() {

    vector<tuple<string, long double, long double, long double, long double> > v;
    // v.push_back(make_tuple("ATOM", 41.5, 17/100.0, 0.06, 0));
    // v.push_back(make_tuple("ADA", 1735, 3.03/100.0, 0.2, 0));
    v.push_back(make_tuple("SUI Scallop", 2539.84, 60.0/100.0, 0.04, 0.3/100));
    v.push_back(make_tuple("SUI Scallop", 2556.32, 60.0/100.0, 0.04, 0.3/100));
    v.push_back(make_tuple("SUI Sui Land", 2539.84, 20/100.0, 0.01, 0));
    v.push_back(make_tuple("EigenLayer",110.0, 3.77/100.0, 0.3, 0));
    // v.push_back(make_tuple("SUI Scallop", 25398.4, 60.0/100.0, 0.04, 0.3/100));
    // v.push_back(make_tuple("SUI Scallop", 253984.0, 60.0/100.0, 0.04, 0.3/100));
    // v.push_back(make_tuple("SUI Bucket", 330, 30.0/100.0, 0.06, 0.3/100));
    int total_seconds = 365 * 24 * 60 * 60; // 一年的總秒數
    long double jump = 0.01;
    long double max_value = 0;
    long double optimoal_A;
    // long double jump = 0.0000000000000000001;
    for(auto& [name, S0, ratio, Fee, slip] : v) {
        max_value = S0;
        for(long double A = jump; A <= S0; A += jump) {
            long double result = totle_APR(S0, ratio, Fee, slip, total_seconds, A);
            if (result > max_value) {
                max_value = result;
                optimoal_A = A;
            }
        }
        cout << fixed << setprecision(9);
        cout << name << endl;
        cout << "Accumulated A " << optimoal_A + Fee << " T1 = " << (optimoal_A+Fee)*total_seconds / (S0 * ratio)/86400.0<<" days" <<endl;
        cout << "Initial value: " << S0<<" ";
        cout << "Max value: " << max_value << endl;
        cout << "Original APY: " << ratio * 100.0 << "% ";
        cout << "APY: " << (max_value - S0) / S0 * 100 << "% ";
        cout << "Max APY: " << exp(ratio) * 100.0 - 100.0 << "%" << endl
        << endl;
    }

    return 0;
}

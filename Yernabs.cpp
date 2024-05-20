#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
long double totle_APR(long double S0, long double ratio, long double Fee, long double slip, int total_seconds, long double A) {
    long double r = ratio;// second ratio
    long double time = total_seconds;
    long double p = S0;
    while (time >= A/(p*r)) {
        time-= A/(p*r);
        p=p+A-Fee;
    }
    return p+p*r*time;
}
int main() {
    // long double S0 = 712; // atom 41.5 ada 1735 sui 220
    // long double ratio = 54.73 / 100.0; // 16.99 3.03 69
    // long double Fee = 0.06; //  0.06 0.2 0.06
    // long double slip = 0 / 100.0; // 0 0 1.16

    vector<tuple<string, long double, long double, long double, long double> > v;
    v.push_back(make_tuple("ATOM", 41.5, 16.99/100.0, 0.06, 0));
    v.push_back(make_tuple("ADA", 1735, 3.03/100.0, 0.2, 0));
    v.push_back(make_tuple("SUI Scallop", 2000.0, 33.0/100.0, 0.04, 0/100));
    v.push_back(make_tuple("SUI Bucket", 330, 30.0/100.0, 0.06, 0));
    int total_seconds = 365 * 24 * 60 * 60; // 一年的總秒數
    long double jump = 0.000000001;
    // long double jump = 0.0000000000000000001;
    for(auto& [name, S0, ratio, Fee, slip] : v) {
        long double max_value = S0;
        long double op = 0;
        long double ed = S0;
        while (op <= ed) {
            // if(op - ed < jump) {
            //     op = ed + jump;
            //     break;
            // }
            long double mid = (op + ed) / 2.0;
            long double tmp = totle_APR(S0, ratio/total_seconds, Fee, slip, total_seconds, mid);
            if (tmp >=max_value) {
                max_value = tmp;
                ed = mid - jump;
            } else {
                op = mid + jump;
            }
        }
        cout << fixed << setprecision(9);
        cout << name << endl;
        cout << "Accumulated A " << op + Fee << " T1 = " << (op+Fee)*total_seconds / (S0 * ratio)/86400.0<<" days" <<endl;
        cout << "Initial value: " << S0<<" ";
        cout << "Max value: " << max_value << endl;
        cout << "Original APY: " << ratio * 100.0 << "% ";
        cout << "APY: " << (max_value - S0) / S0 * 100 << "% ";
        cout << "Max APY: " << exp(ratio) * 100.0 - 100.0 << "%" << endl
        << endl;
    }

    return 0;
}

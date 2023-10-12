#include<bits/stdc++.h>
using namespace std;

// Function to perform prime factorization
map<int, int> primeFactorization(int n) {
    map<int, int> factors;
    for(int i = 2; i*i <= n; i++) {
        while(n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if(n > 1) {
        factors[n]++;
    }
    return factors;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        map<int, int> totalFactors;
        for(int i = 0; i < n; i++) {
            map<int, int> factors = primeFactorization(a[i]);
            for(auto p : factors) {
                totalFactors[p.first] += p.second;
            }
        }
        
        bool canEqualize = true;
        for(auto p : totalFactors) {
            if(p.second % n != 0) {
                canEqualize = false;
                break;
            }
        }
        
        if(canEqualize) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}

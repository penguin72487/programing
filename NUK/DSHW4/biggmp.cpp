#include "BCD64.cpp"
#include<string>
#include<iostream>
#include<iomanip>
#include <gmp.h>

#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto diff = duration_cast<nanoseconds>(end - start);
#endif
    using std::cin;
    using std::cout;
    using std::hex;
    using std::ostream;
    using std::string;
    using std::to_string;
    using std::setfill;
    using std::setw;
#define endl "\n"

int main() {
    freopen("ex-in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string a;
    string sig;
    string b;
    cin >> a;
    #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
    #endif
    mpz_t res;
    mpz_init(res);
    mpz_set_str(res, a.c_str(), 10);
    #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<nanoseconds>(end - start);
    #endif
    while(cin >> sig >> b){
        if(b=="STOP"||sig=="STOP"){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
            mpz_out_str(stdout, 10, res);
            cout << endl;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<nanoseconds>(end - start);
            #endif
            mpz_clear(res);
        }
        if(sig=="+"){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
                mpz_t tmp;
                mpz_init(tmp);
                mpz_set_str(tmp, b.c_str(), 10);
                mpz_add(res, res, tmp);
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<nanoseconds>(end - start);
                cout << "\n BCD add Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
        }else if(sig=="-"){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
                mpz_t tmp;
                mpz_init(tmp);
                mpz_set_str(tmp, b.c_str(), 10);
                mpz_sub(res, res, tmp);
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<nanoseconds>(end - start);
                cout << "\n BCD subtract Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
        }else if(sig=="="){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
            mpz_out_str(stdout, 10, res);
            cout << endl;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<nanoseconds>(end - start);
            #endif
            mpz_set_str(res, b.c_str(), 10);
        }


            
    }
}

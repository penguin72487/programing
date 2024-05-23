#include "BigBCD.hpp"
#define endl "\n"
int main(){
    freopen("ex-in.txt", "r", stdin);
    freopen("ex-out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string a;
    string sig;
    string b;
    cin >> a;
    #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
    #endif
    BigBCD res(a);
    #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD encode Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
    #endif
    while(cin >> sig >> b){
        if(b=="STOP"||sig == "STOP"){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
            cout << res << endl;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD output Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
            break;
        }
        if(sig == "+"){
            BigBCD B(b);
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif

            res = res + B;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD Add Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
        }else if(sig == "-"){
            res = res - BigBCD(b);
        }else if (sig == "="){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
            cout << res << endl;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD output Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
            res = BigBCD(b);
            
        }

    }

    return 0;
}
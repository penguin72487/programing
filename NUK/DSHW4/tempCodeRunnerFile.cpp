freopen("ex-in.txt", "r", stdin);
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string a;
    string sig;
    string b;
    cin >> a;
    BigBCD res(a);
    while(cin >> sig >> b){
        if(b=="STOP"||sig == "STOP"){
            cout << res << endl;
            break;
        }
        if(sig == "+"){
            #ifdef ENABLE_TIMING
                #include <chrono>
                using namespace std::chrono;
                auto start = high_resolution_clock::now();
            #endif
            res = res + BigBCD(b);
            #ifdef ENABLE_TIMING
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(stop - start);
                cout << "\nTotal time taken: " << double (duration.count())/1000000.0 << " ms.\n";
            #endif
        }else if(sig == "-"){
            res = res - BigBCD(b);
        }else if (sig == "="){
            cout << res << endl;
            res = BigBCD(b);
        }

    }
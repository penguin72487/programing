#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class matrix {
protected:

    int n, m;

public:
    matrix(int n, int m) : n(n), m(m){}
    
    virtual ~matrix() = default; // Destructor should also be virtual

    virtual void transpose()=0; // Example of a pure virtual function for polymorphic behavior

    // Define virtual stream operators as member functions or outside class
    virtual ostream& print(ostream& os) const = 0; // Example of a pure virtual function for polymorphic behavior
    virtual void input(vector<tuple<int, int, int>>& vt_Input)  = 0;
};
class matrixO : public matrix {

    vector<vector<int>> mat;
public:
    matrixO(int n, int m) : matrix(n, m){
        mat.resize(n, vector<int>(m, 0));
    }
    ~matrixO() = default; 

    void transpose() override {
        vector<vector<int>> transpose(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                transpose[j][i] = mat[i][j];
            }
        }
        mat = transpose;
        swap(n, m);
    }

    ostream& print(ostream& os) const override {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                os << mat[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    void input(vector<tuple<int, int, int>>& vt_Input) override {
        for(auto& [a, b, c]: vt_Input){
            mat[a][b] = c;
        }
    }


};

class matrixT : public matrix {

    vector<tuple<int, int, int>> mat;
public:
    matrixT(int n, int m) : matrix(n, m) {
        mat.resize(n);
    }
    ~matrixT() = default;

    void transpose() override {
        vector<tuple<int, int, int>> transpose;
        for(int i=0;i<=m;++i){
            for(auto& [a, b, c]: mat){
                if(b == i){
                    transpose.push_back({b, a, c});
                }
            }
        }
        mat = transpose;
        swap(n, m);
    }

    ostream& print(ostream& os) const override {
        for(auto& [a, b, c]: mat){
            os << a << " " << b << " " << c << endl;
        }
        return os;
    }

    void input(vector<tuple<int, int, int>>& vt_Input) override {
        mat = vt_Input;
    }

};
class matrixFT : public matrix {

    vector<tuple<int, int, int>> mat;
public:
    matrixFT(int n, int m) : matrix(n, m) {
        mat.resize(n);
    }
    ~matrixFT() = default;

    void transpose() override {
        vector<tuple<int, int, int>> transpose(mat.size());
        vector<int> count(m+1, 0);
        for(auto& [a, b, c]: mat){
            count[b]++;
        }
        vector<int> pos(m+1, 0);
        for(int i=1;i<=m;++i){
            pos[i] = pos[i-1] + count[i-1];
        }
        for(auto& [a, b, c]: mat){
            transpose[pos[b]++] = {b, a, c};
        }
        mat = transpose;
        swap(n, m);
    }

    ostream& print(ostream& os) const override {
        for(auto& [a, b, c]: mat){
            os << a << " " << b << " " << c << endl;
        }
        return os;
    }

    void input(vector<tuple<int, int, int>>& vt_Input) override {
        mat = vt_Input;
    }

};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    stringstream ss;
    int a, b, c;
    vector<tuple<int, int, int>> vt_input;
    while (cin >> a >> b >> c) {
        vt_input.push_back({a, b, c});
    }
    
    
    matrix* mat = new matrixO(n, m);
    mat->input(vt_input);
    cout << "Traditional matrix:\n";
    cout << "\nOriginal matrix:\n";
    mat->print(cout);
    cout << "\nTranspose matrix:\n";


    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        vector<nanoseconds> time;
        auto start = high_resolution_clock::now();
    #endif

    mat->transpose();   


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();

    #endif

    mat->print(cout);
    delete mat;
    cout << "\nTraditional matrix:";
    #ifdef ENABLE_TIMING
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ns.\n";
        time.push_back(duration);
    #endif
    
    cin >> n >> m;
    mat = new matrixT(n, m);
    mat->input(vt_input);
    cout << "\nTranspose matrix:\n";
    cout << "\nOriginal matrix:\n";
    mat->print(cout);
    cout << "\nTranspose matrix:\n";

    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif

    mat->transpose();

    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
    #endif

    mat->print(cout);
    delete mat;
    cout << "Transpose matrix:";
    #ifdef ENABLE_TIMING
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ns.\n";
        time.push_back(duration);
    #endif


    cin >> n >> m;
    mat = new matrixFT(n, m);
    mat->input(vt_input);

    cout << "\nOriginal matrix:\n";
    mat->print(cout);
    cout << "\nTranspose matrix:\n";

    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif

    mat->transpose();

    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
    #endif

    mat->print(cout);
    delete mat;
    cout << "Fast Transpose matrix:";
    #ifdef ENABLE_TIMING
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ns.\n";
        time.push_back(duration);
        for(auto it:time){
            cout << "Time taken: " << (long double) (it.count())/1000000.0 << " ms.\n";
        }
    #endif




    return 0;
}
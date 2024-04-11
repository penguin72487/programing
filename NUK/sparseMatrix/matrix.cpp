#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
ostream& operator<<(ostream& os, const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            os << matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        matrix[a][b] = c;
    }

    //transpose
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif

    vector<vector<int>> transpose(m, vector<int>(n, 0));
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    cout << matrix << endl;
    cout << "becomes\n\n";
    cout << transpose << endl;



    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> operator*(const vector<std::vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();

    vector<vector<int>> C(m,vector<int>(p, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    vector<vector<int>> A = {{1, 2, 3},
                                       {4, 5, 6}};
    vector<vector<int>> B = {{7, 8},
                                       {9, 10},
                                       {11, 12}};

    vector<vector<int>> result = A*B;

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
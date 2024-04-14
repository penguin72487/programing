#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
string output (char** maze, int n, int m) {
    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += maze[i][j];
        }
        s += "\n";
    }
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    #ifdef ENABLE_TIMING
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    #endif

    string s, cash;
    getline(cin, s);
    int m = s.length() / 2+1;
    cash += s + " ";
    while (cin.peek() != '\n' && getline(cin, s)) {
        cash += s + " ";
        cin.sync();
    }
    int n = cash.length() / m/2;

    cout << cash << endl;
    cash.erase(remove(cash.begin(), cash.end(), ' '), cash.end());

    char** maze = new char*[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new char[m];
        for (int j = 0; j < m; j++) {
            maze[i][j] = cash[i * m + j];
        }
    }

    cout << output(maze, n, m);

    for (int i = 0; i < n; i++) { // Cleanup
        delete[] maze[i];
    }
    delete[] maze;

    #ifdef ENABLE_TIMING
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTotal time taken: " << double (duration.count()) / 1000000.0 << " ms.\n";
    #endif

    return 0;
}

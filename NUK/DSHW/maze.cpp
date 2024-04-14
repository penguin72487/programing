#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
char vec[] = {'\\', '|', '/', '-', '\\', '|', '/', '-'};

bool dfs(char** maze, int n, int m, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] != '0') {
        return 0;
    }
    if(maze[x][y] == 'e')
    {
        return 1;
    }
    maze[x][y] = 'b';
    for (int i = 0; i < 8; i++) {
        if(dfs(maze, n, m, x + dx[i], y + dy[i]))
        {
            maze[x][y] = vec[i];
            return 1;
        }
    }
    return 0;
}

string output (char** maze, int n, int m) {
    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += maze[i][j];
            s+= " ";
        }
        s += "\n";
    }
    s[0]='s';
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

    // cout << cash << endl;
    // cash.erase(remove(cash.begin(), cash.end(), ' '), cash.end());
    s = "";
    for (int i = 0; i < cash.length(); i++) {
        if (cash[i] != ' ') {
            s += cash[i];
        }
    }

    char** maze = new char*[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new char[m];
        for (int j = 0; j < m; j++) {
            maze[i][j] = s[i * m + j];
        }
    }
    maze[0][0] = '0';

    cout << output(maze, n, m);
    maze[0][0] = '0';

    if(dfs(maze, n, m, 0, 0))
    {
        cout << output(maze, n, m)<<endl;
    }
    else
    {
        cout << "Path not found!\n";
    }



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

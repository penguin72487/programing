#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
char vec[] = {'\\', '|', '/', '-', '\\', '|', '/', '-'};
char vec2[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
class Node {
public:
    int x, y;
    Node(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Node() {
        x = -1;
        y = -1;
    }
    friend ostream& operator<<(ostream& os, const Node& n) {
        os << n.x << " " << n.y;
        return os;
    }
};
string output (char** maze, int n, int m,int op_X, int op_Y, int ed_X, int ed_Y) {
    string s;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=m; j++) {

            if(i == op_X && j == op_Y)
                s+= "s";
            else if(i == ed_X && j == ed_Y)
                s+= "e";
            else
                s += maze[i][j];
            // s+= " ";
        }
        s += "\n";
    }
    maze[op_X][op_Y] = '0';
    maze[ed_X][ed_Y] = '0';

    return s;
}
template <class T>
class Stack {// arr type
    T* arr;
    int top_Index;//index of top element
    int max_size;
    
public:
    Stack(int size) {
        arr = new T[size];
        top_Index = -1;
        max_size = size;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(T x) {
        if (top_Index == max_size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top_Index] = x;
    }
    void pop() {
        if (top_Index == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top_Index--;
    }
    T top() {
        if (top_Index == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return arr[top_Index];
    }
    void clear() {
        top_Index = -1;
    }
    bool empty() {
        return top_Index == -1;
    }
    friend ostream& operator<<(ostream& os, const Stack& s) {
        for (int i = 0; i <= s.top_Index; i++) {
            os << s.arr[i] << " ";
        }
        return os;
    }

    
};
bool dfs(char** maze, int n, int m, int op_X, int op_Y, int ed_X, int ed_Y) {
    Stack<Node> s((n+2)*(m+2));
    s.push(Node(op_X, op_Y));
    while (!s.empty()) {
        next:
        Node cur = s.top();

        // if(maze[cur.x][cur.y] != '0')
        //     continue;
        // maze[cur.x][cur.y] = 'b';
        if (cur.x == ed_X && cur.y == ed_Y) {

            return true;
        }
        for (int i = 0; i < 8; i++) {
            int new_X = cur.x + dx[i];
            int new_Y = cur.y + dy[i];
            if (maze[new_X][new_Y] == '0') {
                s.push(Node(new_X, new_Y));
                maze[new_X][new_Y] = vec[i];
                // cout << output(maze, n, m, op_X, op_Y, ed_X, ed_Y);
                // cout << endl;
                goto next;
            }
            
        }
        maze[cur.x][cur.y] = 'b';
        // cout << s << endl;
        s.pop();
    }
    return false;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    freopen("test3.in", "r", stdin);
    freopen("output.txt", "w", stdout);
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
    for (int i = 0; i < int(cash.length()); i++) {
        if (cash[i] != ' ') {
            s += cash[i];
        }
    }

    char** maze = new char*[n+2];
    for(int i = 0; i < n+2; i++)
    {
        maze[i] = new char[m+2];
    }
    for (int i = 0; i < n; i++) {
        // maze[i] = new char[m+2];
        for (int j = 0; j < m; j++) {
            maze[i+1][j+1] = s[i * m + j];
        }
    }
    // maze[0][0] = '0';


    // maze[0][0] = '0';
    int op_X = 0, op_Y = 0;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=m; j++) {
            if(maze[i][j] == 's')
            {
                op_X = i;
                op_Y = j;
            }
        }
    }
    int ed_X=0, ed_Y=0;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=m; j++) {
            if(maze[i][j] == 'e')
            {
                ed_X = i;
                ed_Y = j;
            }
        }
    }
    maze[op_X][op_Y] = '0';
    maze[ed_X][ed_Y] = '0';
    cout << output(maze, n, m ,op_X, op_Y, ed_X, ed_Y)<<"\n";
    char** maze2 = new char*[n+2];
    for(int i = 0; i < n+2; i++)
    {
        maze2[i] = new char[m+2];
    }
    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < m+2; j++) {
            maze2[i][j] = maze[i][j];
        }
    }

    if(dfs(maze2, n, m, op_X, op_Y, ed_X, ed_Y))
    // if(dfs(maze, n, m, ed_X, ed_Y, op_X, op_Y))
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(maze2[i+1][j+1] == '-'||maze2[i+1][j+1] == '|'||maze2[i+1][j+1] == '/'||maze2[i+1][j+1] == '\\')
                {
                    maze[i+1][j+1] = maze2[i+1][j+1];
                }
            }
        }
        cout << output(maze, n, m ,op_X, op_Y, ed_X, ed_Y);
    }
    else
    {
        cout << "Path not found!\n";
    }



    for (int i = 0; i < n; i++) { // Cleanup
        delete[] maze[i];
    }
    delete[] maze;
    for (int i = 0; i < n; i++) { // Cleanup
        delete[] maze2[i];
    }
    delete[] maze2;

    #ifdef ENABLE_TIMING
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTotal time taken: " << double (duration.count()) / 1000000.0 << " ms.\n";
    #endif

    return 0;
}
/*
s 0 0 b 0
b b 0 b 0
0 b 0 b b
0 b b 0 e



*/
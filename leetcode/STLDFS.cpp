#include<iostream>
#include<stack>
using namespace std;

class node{
public:
    int x;
    int y;
    int v_Type;
    node (int a,int b,int c){
        x = a;
        y = b;
        v_Type = c;
    }
};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, m;
void maze_DFS(node* &now);
char maze[12][12];
int main()
{
    
    cin >> n >> m;
    
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < n;++i)
    {
        if(maze[i][0]=='X')
        {
            node *tmp = new node(i, 1, 0);
            maze_DFS(tmp);
            delete tmp;
            break;
        }
    }
}
void maze_DFS(node* &tmp)
{
    stack<node *> STL;
    STL.push(tmp);
    while(!STL.empty())
    {
        node *now = STL.top();
        int x = now->x;
        int y = now->y;
        int v_Type = now->v_Type;
        delete STL.top();
        STL.pop();
        
        maze[x][y] = 'X';
        if(y==11)
        {
            for (int i = 0; i < n;++i)
            {
                for (int j = 0; j < m;++j)
                {
                    cout << maze[i][j];
                }
                cout << "\n";
            }
            cout << "\n";
            while(!STL.empty())
            {
                delete STL.top();
                STL.pop();
            }
            return;
        }
        for (int i = 0; i < n;++i)
        {
            for (int j = 0; j < m;++j)
            {
                cout << maze[i][j];
            }
            cout << "\n";
        }
        cout<< "\n";
        for (int i = 1; i >-2;--i)
        {
            if (maze[x + dx[(v_Type + i+4) % 4]][y + dy[(v_Type + i+4) % 4]] == '.')
            {
                
                STL.push(new node(x + dx[(v_Type + i+4) % 4], y + dy[(v_Type + i+4) % 4], (v_Type + i+4) % 4));
            }
        }
    }
}
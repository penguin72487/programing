#include<bits/stdc++.h>
using namespace std;
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int n, m;
    int l = 0;

    while(cin >> n >> m)
    {
        ++l;
        if(n == 0&&m==n)
        {
            break;
        }
        else {
            if(l!=0)
            cout << "\n";
        }
        int n2 = n + 2, m2 = m + 2;
        vector<vector<int>> matrix(n2, vector<int>(m2, 0));
        char c;
        int dx[] = {0,1,1,1,0,-1,-1,-1};
        int dy[] = {1,1,0,-1,-1,-1,0,1};
        for(int i = 1; i < n+1;++i)
        {
            for(int j = 1; j < m+1;++j)
            {
                cin >> c;
                if(c == '*')
                {
                    matrix[i][j] = -2147483647;
                    for (int k = 0; k < 8;++k){
                        ++matrix[i + dx[k]][j + dy[k]];
                    }
                }
            }
        }
        cout << "Field #" << l << ":\n";
        for(int i = 1; i < n+1;++i)
        {
            for(int j = 1; j < m+1;++j)
            {
                if(matrix[i][j]<0)
                {
                    cout << "*";
                }
                else {
                    cout << matrix[i][j];
                }
            }
            cout << "\n";
        }

    }
        

    return 0;
}
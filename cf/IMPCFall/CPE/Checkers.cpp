#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> maze_Path(n,vector<int>(n,0));
        int op_X=0;
        int op_Y=0;
        char c;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin >> c;
                if(c=='B')
                {
                    op_X=i;
                    op_Y = j;
                }
                else if(c=='B')
                {
                    maze_Path[i][j] = -1;
                }
            }
        }
        // int dx[] = {-1,-1,-2,-2};
        // int dy[] = {-1, 1, -2, 2};

    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
pair<int, int> op;
pair<int, int> ed;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}; // 0 R, 1 RU, 2 U, 3 LU, 4 L, 5 LD, 6 D, 7 RD;
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//string abs_direct[8] = {"R", "RU", "U", "LU", "L", "LD", "D", "RD"};
long long dist_pow2(int x,int y)
{
    return (x - ed.first) * (x - ed.first) + (y - ed.second) * (y - ed.second);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    // unordered_map<string, int> si_dist;
    // for (int i = 0; i < 8;++i)
    // {
    //     si_dist[abs_direct[i]] = i;
    // }
    char c_Cash[4];
    for (int i = 0; i < 4;++i)
    {
        cin >> c_Cash[i];
    }
    op.first = int('9' - c_Cash[1]);
    op.second = int(c_Cash[0] - 'a')+1;
    ed.first = int('9' - c_Cash[3]);
    ed.second = int(c_Cash[2] - 'a')+1;
    //int n=10,m=10;
    // int maze[10][10];
    // for(int i=0;i<10;++i)
    // {
    //     for(int j=0;j<10;++j)
    //     {
    //         maze[i][j] = (i - ed.first) * (i - ed.first) + (j - ed.second) * (j - ed.second);
    //     }
    // }

    //int ans_Count=0;
    vector<int> ans;
    int x = op.first;
    int y = op.second;
    //string ans_Cash="";
    int min_Dist = 2147483647;
    int min_direct;
    while(!(x==ed.first && y==ed.first))
    {
        
        for (int i = 0; i < 8;++i)
        {
            if(dist_pow2(x+dx[i],y+dy[i])<min_Dist)
            {
                //ans_Cash = abs_direct[i];
                min_direct = i;
            }
        }
        ans.push_back(min_direct);
        x += dx[min_direct];
        y += dy[min_direct];
    }
    cout<<ans.size()<<"\n";
    //string abs_direct[8] = {"R", "RU", "U", "LU", "L", "LD", "D", "RD"};
    for(auto it=ans.begin(); it!=ans.end();++it)
    {
        //cout << abs_direct[*it] << "\n";
        switch(*it)
        {
            case 0:
                cout << "R\n";
                break;
            case 1:
                cout << "RU\n";
                break;
            case 2:
                cout << "U\n";
                break;
            case 3:
                cout << "LU\n";
                break;
            case 4:
                cout << "L\n";
                break;
            case 5:
                cout << "LD\n";
                break;
            case 6:
                cout<< "D\n";
                break;
            case 7:
                cout << "RD\n";
                break;
        }
    }
}
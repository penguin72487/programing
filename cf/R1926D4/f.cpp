#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
    int dx[] = {-1,-1,1,1};
    int dy[] = {-1,1,1,-1};
bool is_center(vector<string> &m, int x, int y)
{
    for(int i=0;i<4;i++)
    {
        if(m[x+dx[i]][y+dy[i]]!='B')
        {
            return false;
        }
    }
    return true;
}
vector<vector<int>> count_Cross(set<pair<int, int>> &center)
{
    vector<vector<int>> cross(7, vector<int>(7,0));
    for(auto c:center)
    {
        auto [x1, y1] = c;
        // cross[x1][y1] =  1;
        for(int i=0;i<4;i++)
        {
            cross[x1+dx[i]][y1+dy[i]]++;
        }
    }
    return cross;
}
vector<pair<int,int>>get_max_cross_Spot(vector<vector<int>> &cross)
{
    int max_cross = 0;
    vector<pair<int,int>> max_spot;
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
            if(cross[i][j]>max_cross)
            {

                max_spot.clear();
                max_spot.push_back({i,j});
                max_cross = cross[i][j];
            }
            else if(cross[i][j]==max_cross)
            {
                max_spot.push_back({i,j});
            }
        }
    }
    return max_spot;
}
set<pair<int, int>> get_Center(vector<string> &m)
{
    set<pair<int, int>> center;
    for (int i = 1;i<6;i++)
    {
        for (int j = 1;j<6;j++)
        {
            if(m[i][j]=='B')
            {
                if(is_center(m, i, j))
                {
                    center.insert({i,j});
                }

            }
        }
    }
    return center;
}
ostream& operator<<(ostream& o, vector<vector<int>> m)
{
    for(auto i:m)
    {
        for(auto j:i)
        {
            o<<j<<" ";
        }
        o<<endl;
    }
    return o;
}
void dfs(vector<string> m, int x, int y,int step,int& ans)
{
    m[x][y] = 'W';
    set<pair<int, int>> center = get_Center(m);
    vector<vector<int>> cross = count_Cross(center);
    if(center.size()==0)
    {
        ans=min(ans,step);
        return;
    }
    // cout<<cross<<endl;
    auto max_spot = get_max_cross_Spot(cross);
    for(auto [i,j]:max_spot)
    {
        dfs(m, i, j, step+1, ans);
    }
}
int main() {
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int t;
    cin>>t;
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    while (t--)
    {
        vector<string> m(7);
        for(int i=0;i<7;i++)
        {
            cin>>m[i];
        }
        int ans = INT_MAX;
        set<pair<int, int>> center = get_Center(m);
        vector<vector<int>> cross = count_Cross(center);
        auto max_spot = get_max_cross_Spot(cross);
        for(auto [i,j]:max_spot)
        {
            dfs(m, i, j, 0, ans);
        }
        cout<<ans<<endl;
        
    }
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}

/*
4
WWWWWWW
WWWWBBB
WWWWWBW
WWBBBBB
WWWBWWW
WWBBBWW
WWWWWWW
WWWWWWW
WWWWWWW
WBBBBBW
WBBBBBW
WBBBBBW
WWWWWWW
WWWWWWW
WWWWWWW
WWWWWWW
WWWWWWW
WWWWWWW
WWWWWWW
WWWWWWW
WWWWWWW
WBBBBBW
BBBBBBB
BBBBBBB
WWWWWWW
BBBBBBB
BBBBBBB
BBBBBBB

1
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
*/
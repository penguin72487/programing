#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<int> &min_P = points[0];
        int index = -1;
        int i = 0;
        for(int n=points.size(); i < n; ++i)
        {
            if(points[i][0]==x||points[i][1]==y)
            {
                min_P = points[i];
                index = i;
                //++i;
                break;
            }
        }
        if(index==-1)
        {
            return -1;
        }
        for(int n=points.size(); i < n; ++i)
        {
            if(points[i][0]==x||points[i][1]==y)
            {
                if(Manhattan_distance(x,y,points[i][0],points[i][1])<Manhattan_distance(x,y,min_P[0],min_P[1]))
                {
                    min_P = points[i];
                    index = i;
                }
            }
        }
        return index;
    }
    int Manhattan_distance(int x,int y,int x2,int y2) 
    {

        return abs(x-x2)+abs(y-y2);
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    int x=75, y=60;
    //vector<vector<int>> points={{1,2},{3,1},{2,4},{2,3},{4,4}};
    vector<vector<int>> points = {{49, 45}, {22, 87}, {22, 22}, {23, 37}, {137, 31}, {5, 146}, {75, 149}, {121, 72}, {66, 1}, {65, 37}, {58, 132}, {95, 145}, {118, 131}, {17, 79}, {126, 119}, {126, 66}, {20, 80}, {87, 117}, {57, 138}, {135, 115}, {114, 152}, {14, 54}, {68, 65}, {104, 68}, {58, 5}, {8, 75}, {50, 36}, {3, 12}, {28, 73}, {36, 71}, {114, 12}, {97, 116}, {139, 153}, {29, 7}, {100, 84}, {139, 92}, {126, 2}, {72, 31}, {28, 12}, {145, 60}, {122, 119}, {124, 47}, {118, 70}, {143, 105}, {138, 146}, {55, 55}, {1, 128}, {95, 26}, {96, 145}, {142, 152}, {52, 39}, {1, 22}, {40, 96}, {1, 143}, {100, 132}, {44, 81}, {140, 17}, {12, 23}, {32, 28}, {5, 24}, {68, 50}, {69, 77}, {109, 89}, {149, 145}, {138, 80}, {38, 70}, {76, 79}, {144, 103}, {144, 24}, {98, 41}, {3, 1}, {57, 29}, {51, 7}, {5, 38}, {111, 74}, {111, 141}, {77, 90}, {31, 54}, {115, 121}, {23, 30}, {71, 69}, {94, 133}, {38, 15}, {14, 48}, {57, 19}, {128, 56}, {39, 44}};
    cout<<s.nearestValidPoint(x,y,points);
}
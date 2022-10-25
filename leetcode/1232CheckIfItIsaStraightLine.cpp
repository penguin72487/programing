#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool flag=1;
        int dx=coordinates[0][0]-coordinates[1][0], dy=coordinates[0][1]-coordinates[1][1];

        simp(dx, dy);
        for(auto it=next(coordinates.begin()); it!=coordinates.end();++it)
        {
            int ddx = (*it)[0]-coordinates[0][0];
            int ddy = (*it)[1]-coordinates[0][1];
            simp(ddx, ddy);
            if(dx==ddx && dy==ddy)
            {
                continue;
            }
            else {
                flag=0;
                break;
            }
        }
        return flag;
    }
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    void simp(int &a,int &b)
    {   
        int t=gcd(a,b);
        a /= t;
        b/= t;
        return;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<vector<int>> num = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    cout << s.checkStraightLine(num);
}
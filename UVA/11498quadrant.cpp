#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,int> divsion_point , points;
    int cases;
    while(cin >> cases && cases)
    {
        cin >> divsion_point.first >> divsion_point.second;
        for(int i = 0 ; i < cases; i++)
        {
            cin >> points.first >> points.second;
            if(points.first == divsion_point.first || points.second == divsion_point.second)
            {
                printf("divisa\n");
            }
            else if(points.first > divsion_point.first && points.second > divsion_point.second)
            {
                printf("NE\n");
            }
            else if(points.first < divsion_point.first && points.second > divsion_point.second)
            {
                printf("NO\n");
            }
            else if (points.first < divsion_point.first && points.second < divsion_point.second)
            {
                printf("SO\n");
            }
            else if(points.first > divsion_point.first && points.second < divsion_point.second)
            {
                printf("SE\n");
            }
        }
    }
    return 0;
}
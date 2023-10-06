#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int matrix[3][10];
    for (int i = 0; i < 3;++i)
    {
        for(int j = 0; j < 10;++j)
        {
            matrix[i][j] =pow(j,i+1);
        }
    }
    int limit = 1;
    for (int i = 0; i < 3;++i)
    {
        limit = (limit << 3) + (limit << 1);
        set<int> tmp;
        int sum = 0;
        for(int i = 0,t=i+1; i < t;++i)
        {
            for (int j = 0; j < 10;++j)
            {
                
            }
        }


    }


    


        return 0;
}
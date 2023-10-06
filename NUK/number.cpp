#include<iostream>
#include<algorithm>
#include<cmath>
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
        for(int j = 9; j >0;--j)
        {
            for (int k = 0; k < 9;++k)
            {
                if(matrix[i][j]+matrix[j][k]>limit)
                {
                    break;
                }
                if(matrix[i][j]+matrix[i][k]==matrix[i][j])
                {
                    cout << matrix[i][k]<<matrix[i][j] << "\n";
                    cout << matrix[i][j]<<matrix[i][k] << "\n";

                }
            }
        }
    }


    


        return 0;
}
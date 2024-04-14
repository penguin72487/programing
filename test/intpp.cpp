#include<iostream>
using namespace std;
void get_RC(int matrix[2][7], int R,int C)
{
    int (*tmp)[2][7] = &matrix;
    R = &matrix;
    C = 0;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int matrix[2][7]={{3,6,3,6,2147483647,1,3},{3,6,3,-49,8,1,3}};
    int R, C;
    get_RC(matrix,R,C);
    cout<<R<<" "<<C<<"\n";
    return 0;
}
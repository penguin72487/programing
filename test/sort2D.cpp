#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int matrix[2][7]={{3,6,3,6,2147483647,1,3},{3,6,3,-49,8,1,3}};
    sort(matrix[0],matrix[0]+2*7);
    for (int i=0; i < 2;++i){
        for (int j=0; j < 7;++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
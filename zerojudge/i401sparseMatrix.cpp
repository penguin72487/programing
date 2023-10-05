#include<iostream>
#include<set>
#include<map>
using namespace std;
class node{
public:
    int x;
    int y;
    int type;
    node(int t_X,int t_Y,int t_Ty){
        x=t_X;
        y=t_Y;
        type=t_Ty;// 0 / 1 \/
    }


};
class sparse_Matrix{
    public:
    set<int> idX;
    set<int> idY;
    map<int, map<int, node>> matrix;
    map<int ,node>& operator[] (int i)
    {
        return matrix[i];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int t_X,t_Y,t_Ty;
    sparse_Matrix matrix;
    
    for (int i = 0; i < n;++i)
    {
        cin>>t_X>>t_Y>>t_Ty;
        matrix[t_X][t_Y] =node(t_X,t_Y,t_Ty);
        

    }
}
#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class node
{
    int index;
    int val;

public:
    node ()
    {

    }
    node (int t_dex,int t_Val)
    {
        index = t_dex;
        val = t_Val;
    }
    bool operator()(node val,node val2)
    {
        if(val.val == val2.val)
        {
            return (val.index < val2.index);
        }
        else
        {
            return (val.val < val2.val);
        }
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    
    

}
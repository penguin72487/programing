#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string val;
    string val2;
    cin >> val>>val2;
    bool flag = true;
    for(auto it=val.begin(); it!=val.end();++it){
        if(*it<'0'||*it>'9')
        {
            flag = false;
            break;
        }
    }
    if(!flag){
        cout << "NaN\n";
        return 0;
    }
    for(auto it=val2.begin(); it!=val2.end();++it){
        if(*it<'0'||*it>'9')
        {
            flag = false;
            break;
        }
    }
    if(flag){
        cout << stoi(val) - stoi(val2)<<"\n";
    }
    else
    {
                        cout << "NaN\n";
    }
    return 0;
}
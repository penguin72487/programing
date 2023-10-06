#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int el[7];
    for(int i = 0; i <7; ++i)
    {
        cin>>el[i];
    }
    cout<<*(max_element(el,el+7))-*(min_element(el,el+7))<<'\n';
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(500000,0);
    int i_Max=-1;
    for(int i=0,c; i<n; ++i){
        cin >> c;
        ++v[c - 1];
        i_Max = max(i_Max, c);
    }
    //i_Max = min(i_Max, x);
    for (int i = 0; i <x-1; ++i)
    {
        if(v[i]==0)
        {
            continue;
        }
        else if(v[i]%(i+2)==0)
        {
            v[i + 1] += v[i] / (i + 2);
        }
        else {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
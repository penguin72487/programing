#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
   for(auto& i:a)
    {
        cin >> i;
    }
    if(count_if(a.begin(), a.end(), [](int i) {
       return i == 0;
    })>a.size()/2.0)
    {
       cout << 0;
    }
    else if (count_if(a.begin(), a.end(), [](int i){
         return i > 0; 
    })>=a.size()/2.0)
    {
        cout << 1;
    }
    else if(count_if(a.begin(), a.end(), [](int i){
        return i < 0; 
    })>=a.size()/2.0)
    {
        cout << -1;
    }
    else
    {
            cout << 0;
    }
}
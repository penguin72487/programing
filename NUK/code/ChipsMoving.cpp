#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int odd = 0, even = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] &1 ){
            ++odd;
        }
        else{
            ++even;
        }
    }
    cout << min(odd, even) << "\n";
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool NewBinarySearch(long long *start, long long *end, long long target) {
    end--;
    while (start < end&& *start<=target&& *end>=target) {
        int x=*end-*start;
        int y = end - start;
        auto guess = start+(target-*start) *y / x;
        // cout<<*mid<<endl;
        if (*guess == target) {
            return true;
        }
        auto mid = start + (end - start) / 2;
        if (*mid == target) {
            return true;
        }
        if (*mid < target) {
            start = mid + 1;
        } else {
            end = mid;
        }

        
    }
    return false;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,t;
    cin >> n >> t;
    long long testCases[n];
    for(int i=0; i<n; i++) {
        cin>>testCases[i];
    }
    for(int i=0; i<t; i++) {
        long long target;
        cin>>target;
        if(NewBinarySearch(testCases, testCases+n, target)) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}


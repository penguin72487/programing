#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
auto binary_search(vector<long long>::iterator start, vector<long long>::iterator end, long long target) -> auto {
    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (*mid == target) {
            return true;
        } else if (*mid < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

bool NewBinarySearch(vector<long long>::iterator start, vector<long long>::iterator end, long long target);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,t;
    cin >> n >> t;
    vector<long long> testCases(n);
    for(auto &i: testCases) {
        cin>>i;
    }
    for(int i=0; i<t; i++) {
        int target;
        cin>>target;
        if(NewBinarySearch(testCases.begin(), testCases.end(), target)) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

bool NewBinarySearch(vector<long long>::iterator start, vector<long long>::iterator end, long long target) {
    while (start <= end) {
        auto mid = start + target * distance(start, end) / distance(start, end);
        cout<<*mid<<endl;
        if (*mid == target) {
            return true;
        } else if (*mid < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}
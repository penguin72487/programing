#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    vector<int>a={10, 9, 8, 7, 4, 70, 60, 50};
    int k = 4;
    ++k;
    //int n = a.size();
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> min_Heap;


    auto it = a.begin();
    for(int i=0; i<k; ++i,++it)
    {
        min_Heap.push(*it);
    }
    for (;it!=a.end();++it)
    {
        ans.push_back(min_Heap.top());
        min_Heap.pop();
        min_Heap.push(*it);
    }
    while(!min_Heap.empty())
    {
        ans.push_back(min_Heap.top());
        min_Heap.pop();
    }



    for(auto it=ans.begin();it!=ans.end();++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}
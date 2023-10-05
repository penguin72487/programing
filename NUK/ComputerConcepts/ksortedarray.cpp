#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?ref=gcse
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> min_Heap;
        ++K;
    
        auto it = arr;
        for(int i=0; i<K; ++i,++it)//creat a k+1 min_Heao
        {
            min_Heap.push(*it);
        }
        for (;it!=arr+num;++it) // output one to ans and push one to min_Heap
        {
            ans.push_back(min_Heap.top());
            min_Heap.pop();
            min_Heap.push(*it);
        }
        while(!min_Heap.empty()) no one can push,output all element of min_Heap
        {
            ans.push_back(min_Heap.top());
            min_Heap.pop();
        }
            // Your code here
        return ans;
    }
};*/
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
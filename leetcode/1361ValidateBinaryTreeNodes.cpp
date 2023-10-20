#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> tree(n);
        vector<vector<int>> r_tree(n);
        vector<int> roots;
        for (int i = 0; i < n;++i)
        {
            if (leftChild[i] != -1)
            {
                tree[i].push_back(leftChild[i]);
                r_tree[leftChild[i]].push_back(i);
            } 
            if (rightChild[i] != -1) 
            {
                tree[i].push_back(rightChild[i]);
                r_tree[rightChild[i]].push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if(r_tree[i].size()==0) roots.push_back(i);
        }
        if(roots.size()!=1) return false;
        vector<bool> visited(n, false);
        //cycle(tree, n, 0, visited);
        return (!cycle(tree,roots[0], visited))&&*min_element(visited.begin(), visited.end());
    }
    bool cycle(vector<vector<int>>& tree, int i, vector<bool>& visited) {
        if (visited[i]) return true;
        visited[i] = true;
        for (int j = 0; j < tree[i].size(); ++j) {
            if (cycle(tree, tree[i][j], visited)) return true;
        }
        return false;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    int n = 4;
    vector<int> leftChild = {1,-1,3,-1};
    vector<int> rightChild = {2,-1,-1,-1};
    cout << s.validateBinaryTreeNodes(n, leftChild, rightChild) << "\n";
    return 0;
}
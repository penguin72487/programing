#include<bits/stdc++.h>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0){
            return nullptr;
        }
        else if(n==1)
        {
            return new Node(grid[0][0], true);
        }
        else{
            vector<vector<int>> topLeft(n/2, vector<int>(n/2, 0));
            vector<vector<int>> topRight(n/2, vector<int>(n/2, 0));
            vector<vector<int>> bottomLeft(n/2, vector<int>(n/2, 0));
            vector<vector<int>> bottomRight(n/2, vector<int>(n/2, 0));
            for(int i = 0; i < n/2; i++){
                for(int j = 0; j < n/2; j++){
                    topLeft[i][j] = grid[i][j];
                    topRight[i][j] = grid[i][j+n/2];
                    bottomLeft[i][j] = grid[i+n/2][j];
                    bottomRight[i][j] = grid[i+n/2][j+n/2];
                }
            }
            Node* node = new Node();
            node->topLeft = construct(topLeft);
            node->topRight = construct(topRight);
            node->bottomLeft = construct(bottomLeft);
            node->bottomRight = construct(bottomRight);
            if(node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf && node->topLeft->val == node->topRight->val && node->topRight->val == node->bottomLeft->val && node->bottomLeft->val == node->bottomRight->val){
                node->isLeaf = true;
                node->val = node->topLeft->val;
                node->topLeft = nullptr;
                node->topRight = nullptr;
                node->bottomLeft = nullptr;
                node->bottomRight = nullptr;
            }
            return node;
        }
    }

};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    vector<vector<int>> grid = {{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    Solution s;
    s.construct(grid);
    
    return 0;
}
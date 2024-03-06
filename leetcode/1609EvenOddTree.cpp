#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!(root->val&1)){
            return 0;
        }
        vector<int> vi;
        // vi.push_back(0);
        return dfs(root, 0, vi);

    }
    bool dfs(TreeNode* root, int level, vector<int>& vi){
        if(root==nullptr){
            return 1;
        }
        if(vi.size()<=level){
            if(level&1){
                vi.push_back(INT_MAX);
            }
            else{
                vi.push_back(0);
            }
        }
        if(level&1){
            if((root->val&1)||root->val>=vi[level]){
                return 0;
            }
            else{
                vi[level] = root->val;
            }
        }
        else{
            if(!(root->val&1)||root->val<=vi[level]){
                return 0;
            }
            else{
                vi[level] = root->val;
            }
        }
        return dfs(root->left, level+1, vi) && dfs(root->right, level+1, vi);
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(2);

    cout << s.isEvenOddTree(root)<<endl;


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
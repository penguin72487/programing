/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        order_Traversal(root);
        return root;
    }
    void order_Traversal(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        swap(root->left, root->right);
        order_Traversal(root->left);
        order_Traversal(root->right);
    }    
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;

    return 0;
}
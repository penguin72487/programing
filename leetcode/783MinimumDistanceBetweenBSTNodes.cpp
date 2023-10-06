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
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        return inorder_Traversal(root,root->val);
    }
    int inorder_Traversal(TreeNode* root,int pa_Val)
    {
        if(root == nullptr)
        {
            return 100001;
        }
        return min(abs(root->val - pa_Val), min(inorder_Traversal(root->left, root->val), inorder_Traversal(root->right, root->val)));
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        order_Traversal(root, 1, ans);
        for(int i = 0; i < ans.size(); i++)
        {
            if(i%2 == 1)
            {
                reverse(ans[i].begin(), ans[i].end());
            }
        }  
        return ans;      
    }
    void order_Traversal(TreeNode* root, int level, vector<vector<int>>& ans)
    {
        if(root == nullptr)
        {
            return;
        }
        if(ans.size() < level)
        {
            ans.push_back(vector<int>());
        }
        ans[level-1].push_back(root->val);
        order_Traversal(root->left, level+1, ans);
        order_Traversal(root->right, level+1, ans);
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;

    return 0;
}
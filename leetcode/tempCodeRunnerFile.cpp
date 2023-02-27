class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> a;
        tuple<int, int, int> tiii = {0, 2147483647, 2147483647};
        inorder_Traversal(root, a,tiii);
        return get<2>(tiii);
    }
    tuple<int,int,int> inorder_Traversal(TreeNode* root, vector<int>& a,tuple<int,int,int>& tiii)// find max of left node and min of right node
    {
        if(root == nullptr)
        {
            return {0, 2147483647, 2147483647};
        }
        
        
        int max_left = get<0>(inorder_Traversal(root->left, a,tiii));
        int min_right = get<1>(inorder_Traversal(root->right, a, tiii));
        int min_diff = abs(root->val - max_left);
        return {max_left,min_right,min_diff};
    }
};
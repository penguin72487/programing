#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left=nullptr;
    TreeNode *right=nullptr;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(vector<int>& tree)
    {
        if(tree.size() == 0)
        {
            return;
        }
        val = tree[0];
        queue<TreeNode*> q;
        q.push(this);
        int i = 1;
        while(i < tree.size())
        {
            TreeNode* now = q.front();
            q.pop();
            if(tree[i] != -1)
            {
                now->left = new TreeNode(tree[i]);
                q.push(now->left);
            }
            i++;
            if(i < tree.size() && tree[i] != -1)
            {
                now->right = new TreeNode(tree[i]);
                q.push(now->right);
            }
            i++;
        }
    }
    ~TreeNode()
    {
        disnode(this);
    }
    void disnode(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        disnode(root->left);
        disnode(root->right);
        delete root;
    }
};
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
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> tree={90,69,-1,49,89,-1,52};
    cout<<s.minDiffInBST(new TreeNode(tree))<<"\n";


    return 0;
}
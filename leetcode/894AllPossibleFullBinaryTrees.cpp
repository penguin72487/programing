#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
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
    unordered_map<int,vector<TreeNode*>> mp_it;
    //vector<TreeNode*> vt;
    vector<TreeNode*> allPossibleFBT(int n) {
        build(nullptr,nullptr,n);
        return mp_it[n];
    }
    vector<TreeNode*> build(TreeNode* head,TreeNode* now,int n)
    {
        if(mp_it.find(n)!=mp_it.end())
        {
            return mp_it[n];
        }
        if(n==1)
        {
            return mp_it[1]=vector<TreeNode*>{new TreeNode(0)};
        }
        vector<TreeNode *> ans;
        for (int i = 1;i<n;i+=2)
        {
            vector<TreeNode*> left = build(head,now,i);
            vector<TreeNode*> right = build(head,now,n-i-1);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mp_it[n] = ans;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    s.allPossibleFBT(7);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        preorder(root,0);
        return ans;
    }
    void preorder(Node* root,bool &&flag)
    {
        if(!root)
        {
            return;
        }
        ans.push_back(root->val);
        for (auto it = root->children.begin(); it != root->children.end();++it)
        {
            preorder(*it,0);
        }
    }

};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout<<s.fib(40);
}
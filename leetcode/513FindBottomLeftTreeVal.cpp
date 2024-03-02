#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

//  * Definition for a binary tree node.
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
    int findBottomLeftValue(TreeNode* root) {

        int maxDepth = 0;
        int leftmostValue = root->val;
        return findBottomLeftValue(root, 0, maxDepth, leftmostValue);
        

    }
    int findBottomLeftValue(TreeNode* root, int depth, int& maxDepth, int& leftmostValue) {
        if (root == nullptr) {
            return 0;
        }
        if (depth > maxDepth) {
            maxDepth = depth;
            leftmostValue = root->val;
        }
        findBottomLeftValue(root->left, depth + 1, maxDepth, leftmostValue);
        findBottomLeftValue(root->right, depth + 1, maxDepth, leftmostValue);
        return leftmostValue;
    
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
    cout << s.findBottomLeftValue(new TreeNode(2, new TreeNode(1), new TreeNode(3))) << endl;



    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}
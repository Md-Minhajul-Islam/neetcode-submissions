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
    bool flag = 1;

    int dfs(TreeNode* root)
    {
        if(!root) return 0;

        int fromLeft = 0, fromRight = 0;
        if(root->left) fromLeft = dfs(root->left)+1;
        if(root->right) fromRight = dfs(root->right)+1;

        if(abs(fromLeft - fromRight) > 1)
        {
            flag = 0;
            return 1e9;
        }

        return max(fromLeft, fromRight);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};

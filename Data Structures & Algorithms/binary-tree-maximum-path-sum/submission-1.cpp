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
    int maxSum = -1e9;

    int maxPathSumHelper(TreeNode* root)
    {
        if(!root) return 0;

        int leftMax = maxPathSumHelper(root->left);
        int rightMax = maxPathSumHelper(root->right);

        if(leftMax < 0) leftMax = 0;
        if(rightMax < 0) rightMax = 0;

        maxSum = max(maxSum, root->val+leftMax+rightMax);

        return root->val+max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        
        maxPathSumHelper(root);

        return maxSum;
    }
};

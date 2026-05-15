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

    bool checkValid(TreeNode* root, int low, int high)
    {
        if(!root) return true;

        if(root->val <= low || root->val >= high) return false;

        return checkValid(root->left, low ,root->val)
            && checkValid(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
       
       return checkValid(root, -1e5, 1e5);       
    }
};

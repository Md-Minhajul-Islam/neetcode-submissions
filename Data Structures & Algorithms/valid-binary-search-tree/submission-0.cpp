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

    bool checkValid(TreeNode* root, int low, int high, bool flag)
    {
        if(!root) return true;

        if(root->val <= low || root->val >= high) return false;

        bool leftFlag = checkValid(root->left, low ,root->val, flag);
        bool rightFlag = checkValid(root->right, root->val, high, flag);

        if(!leftFlag || !rightFlag) flag = false;
        return flag;
    }

    bool isValidBST(TreeNode* root) {
       
       return checkValid(root, -1e5, 1e5, true);       
    }
};

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
    int diameter = 0;

    int action(TreeNode* root)
    {
        if(!root) return 0;

        int fromLeft = 0;
        int fromRight = 0;

        if(root->left) fromLeft = action(root->left)+1;
        if(root->right) fromRight = action(root->right)+1;
        diameter = max(fromLeft+fromRight, diameter);

        return max(fromLeft, fromRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        action(root);     

        return diameter;          
    }
};

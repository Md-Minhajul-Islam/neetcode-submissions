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

    void invertAction(TreeNode* root)
    {
        if(root != nullptr)
        {
            swap(root->left, root->right);
        }
        if(root != nullptr && root->left != nullptr) invertAction(root->left);
        if(root != nullptr && root->right != nullptr) invertAction(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        invertAction(root);
        return root;
    }
};

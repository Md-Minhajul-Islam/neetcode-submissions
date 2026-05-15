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

    // inOrderTraverse creates sorted array
    void inOrderTraverse(TreeNode* root, vector<int>& v)
    {
        if(!root) return;

        inOrderTraverse(root->left, v);
        v.push_back(root->val);
        inOrderTraverse(root->right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inOrderTraverse(root, v);
        for(auto& u: v)
        {
            k--;
            if(k == 0) return u;
        }
    }
};

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

    TreeNode* buildTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int, int> mp)
    {
        if(ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(preorder[ps]);
        int numsLeft = mp[preorder[ps]]-is;
        root->left = buildTree(preorder, ps+1, ps+numsLeft, inorder, is, mp[preorder[ps]]-1, mp);
        root->right = buildTree(preorder, ps+numsLeft+1, pe, inorder, mp[preorder[ps]]+1, ie, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};

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
    int maxDepth(TreeNode* root) {
        
        if(root == nullptr) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int depth = 1;
        while(!st.empty())
        {
            auto [node, val] = st.top();
            st.pop();
            depth = max(depth, val);

            if(node->left) st.push({node->left, val+1});
            if(node->right) st.push({node->right, val+1});
        }
        return depth;
    }
};

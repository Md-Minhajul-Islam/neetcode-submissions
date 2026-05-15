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
    int goodNodes(TreeNode* root) {
        
        int cnt = 0;

        if(!root) return cnt;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});
        while(!st.empty())
        {
            auto [node, mx] = st.top();
            st.pop();
            mx = max(mx, node->val);
            if(mx == node->val) cnt++;
            if(node->left) st.push({node->left, mx});
            if(node->right) st.push({node->right, mx});
        }
        return cnt;

    }
};

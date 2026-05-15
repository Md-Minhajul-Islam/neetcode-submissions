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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> cnt(1005);

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            cnt[node->val]++;
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        for(int i = 0; i <= 1000; )
        {
            if(cnt[i]) k--, cnt[i]--;
            else i++;

            if(k == 0) return i;
        }
    }
};

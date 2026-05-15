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

    string serialize(TreeNode* root)
    {
        if(!root) return "$#";

        return "$"+to_string(root->val) +
            serialize(root->left) + serialize(root->right);
    }

    vector<int> Lps(string s)
    {
        vector<int> lps(s.size());

        for(int i = 0, j = 1; j < s.size(); )
        {
            if(s[i] == s[j])
            {
                lps[j] = i+1;
                i++; j++;
            }
            else
            {
                if(i != 0) i = lps[i-1];
                else j++; 
            }
        }
        return lps;
    }

    bool kmp(string text, string pattern)
    {
        vector<int> lps = Lps(pattern);

        for(int i = 0, j = 0; i < text.size(); )
        {
            if(text[i] == pattern[j]) i++, j++;
            else
            {
                if(j != 0) j = lps[j-1];
                else i++;
            }

            if(j == pattern.size()) return true;
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);

        return kmp(serialized_root, serialized_subRoot);
    }
};

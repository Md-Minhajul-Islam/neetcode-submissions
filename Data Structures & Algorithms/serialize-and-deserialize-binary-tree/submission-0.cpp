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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "!#";

        return "!"+to_string(root->val)+serialize(root->left)+serialize(root->right);
    }

    TreeNode* deserialize(string& data, int& i)
    {
        i++;
        if(i >= data.size()) return nullptr;

        if(data[i] == '#')
        {
            i++;
            return nullptr;
        }

        string s = "";
        while(i < data.size() && data[i] != '!') s += data[i++];
        TreeNode* node = new TreeNode(stoi(s));
        node->left = deserialize(data, i);
        node->right = deserialize(data, i);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << '\n';
        int i = 0;
        return deserialize(data, i);
    }
};

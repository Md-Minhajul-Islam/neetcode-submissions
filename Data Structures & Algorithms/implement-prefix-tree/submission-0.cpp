class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto &c: word)
        {
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto& c: word)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto& c: prefix)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

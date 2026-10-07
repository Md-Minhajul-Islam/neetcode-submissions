class Solution {
public:
    unordered_map<string, bool> dict;
    vector<int> memo;
    bool wordBreakHelper(int start, string& s)
    {
        if(start == s.size()) return true;
        if(memo[start] != -1) return memo[start];

        string word = "";
        for(int i = start; i < s.size(); i++)
        {
            word += s[i];
            if(dict.find(word) != dict.end())
            {
                if(wordBreakHelper(i+1, s)) return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dict.clear();
        memo.assign(s.size(), -1);
        for(auto &w: wordDict) dict[w] = true;

        return wordBreakHelper(0, s);
    }
};

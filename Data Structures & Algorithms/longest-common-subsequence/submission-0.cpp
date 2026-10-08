class Solution {
public:
    vector<vector<int>> memo;

    int lcs(int i, int j, string& text1, string& text2)
    {
        if(i >= text1.size() || j >= text2.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        if(text1[i] == text2[j]) return memo[i][j] = 1+lcs(i+1, j+1, text1, text2);
        else return memo[i][j] = max(lcs(i+1, j, text1, text2), lcs(i, j+1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));

        return lcs(0, 0, text1, text2);
    }
};

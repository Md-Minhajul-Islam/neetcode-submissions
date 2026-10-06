class Solution {
public:
    vector<vector<int>> memo;
    int DecodeHelper(int i, string& s, string t)
    {
        if(i == s.size()) return 1;
        if(t.size() == 0 && s[i] == '0') return 0;
        if(memo[i][t.size()] != -1) return memo[i][t.size()];

        int cnt = 0;
        if(t.size() == 1 && (t[0] == '1' || (t[0] == '2' && s[i] <= '6'))) cnt += DecodeHelper(i+1, s, t+s[i]);
        if(s[i] != '0') cnt += DecodeHelper(i+1, s, string(1, s[i]));
        
        return memo[i][t.size()] = cnt;
    }

    int numDecodings(string s) {
        memo = vector<vector<int>>(s.size(), vector<int>(3, -1));
        return DecodeHelper(0, s, "");
    }
};

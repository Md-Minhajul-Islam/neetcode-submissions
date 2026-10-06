class Solution {
public:
    vector<int> memo;
    int numDecodings(string s) {
        memo.assign(s.size(), -1);
        return DecodeHelper(0, s);
    }

    int DecodeHelper(int i, string& s)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(memo[i] != -1) return memo[i];

        int cnt = DecodeHelper(i+1, s);
        if(i+1 < s.size())
        {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) cnt += DecodeHelper(i+2, s);
        }

        return memo[i] = cnt;
    }
};

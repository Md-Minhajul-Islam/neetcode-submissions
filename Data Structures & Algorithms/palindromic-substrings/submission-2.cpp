class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;

        auto expandAroundCenter = [&](int l, int r)
        {
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                cnt++;
                l--; r++;
            }
        };

        for(int i = 0; i < s.size(); i++)
        {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i+1);
        }
        return cnt;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, start = -1;

        auto expandAroundCenter = [&](int i, int j)
        {
            while(i >= 0 && j < s.size() && s[i] == s[j]) i--, j++;
            int len = j-i-1;
            if(len > maxLen)
            {
                maxLen = len;
                start = i+1;
            }
        };

        for(int i = 0; i < s.size(); i++)
        {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i+1);
        }
        return s.substr(start, maxLen);
    }
};

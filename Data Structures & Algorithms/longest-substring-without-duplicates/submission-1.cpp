class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, bool> mp;

        int mxSize = 0;
        int i, j;
        for(i = 0, j = 0; i < s.length(); i++)
        {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] == 1)
            {
                while(s[j] != s[i])
                {
                    mp[s[j]] = 0;
                    j++;
                }
                mp[s[j]] = 0;
                j++;
            }
            mxSize = max(mxSize, i-j+1);
            mp[s[i]] = 1;
        }
        mxSize = max(mxSize, i-j);
        return mxSize;
    }
};

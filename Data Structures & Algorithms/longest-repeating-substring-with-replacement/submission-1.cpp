class Solution {
public:
    int maxCount(vector<int>& cnt)
    {
        int mx = 0;
        for(auto &c: cnt) mx = max(mx, c);
        return mx;
    }

    int characterReplacement(string s, int k) {

        int mxCnt = 0, totalCnt = 0, ans = 0;
        vector<int> cnt(30, 0);

        int left = 0, right = 0;
        while(right < s.size())
        {
            cnt[s[right]-'A']++;
            totalCnt++;
            mxCnt = maxCount(cnt);

            while(totalCnt-mxCnt > k)
            {
                cnt[s[left]-'A']--;
                totalCnt--;
                mxCnt = maxCount(cnt);
                left++;
            }
            ans = max(ans, totalCnt);
            right++;
        }
        return ans;
        
    }
};

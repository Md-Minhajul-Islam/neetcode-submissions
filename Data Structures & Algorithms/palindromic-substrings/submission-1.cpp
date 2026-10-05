class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> hashMap(s.size(), vector<bool>(s.size()));

        auto expandAroundCenter = [&](int l, int r)
        {
            while(l >= 0 && r < s.size() && s[l] == s[r] && hashMap[l][r] == false)
            {
                hashMap[l][r] = true;
                l--; r++;
            }
        };

        for(int i = 0; i < s.size(); i++)
        {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i+1);
        }

        int cnt = 0;
        for(auto &u: hashMap)
        {
            for(auto v: u) if(v) cnt++;
        }
        return cnt;
    }
};

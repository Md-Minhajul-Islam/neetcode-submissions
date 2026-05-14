class Solution {
public:
    bool isExist(unordered_map<char, int>& m1, unordered_map<char, int>& m2)
    {
        for(auto& [u, v]: m2)
        {
            if(m1.find(u) != m1.end() && m1[u] >= v) continue;
            return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        
        unordered_map<char, int> m1, m2;
        
        for(int i = 0; i < t.size(); i++) m2[t[i]]++;

        int mnLen = 1e5;
        pair<int, int> range = {-1, -1};
        for(int l = 0, r = 0; r < s.size(); r++)
        {
            m1[s[r]]++;
            while(isExist(m1, m2))
            {
                if(r-l+1 < mnLen)
                {
                    mnLen = r-l+1;
                    range = {l, r};
                }
                m1[s[l]]--;
                l++;
            }
        }
        string ans = "";
        if(range.first != -1 && range.second != -1)
        {
            for(int i = range.first; i <= range.second; i++) ans += s[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> rightMost(30);
        for(int i = 0; i < s.size(); i++) rightMost[s[i]-'a'] = i;

        int i = 0;
        while(i < s.size())
        {
            int j = rightMost[s[i]-'a'];
            int cnt = 0;
            while(i <= j && i < s.size())
            {
                cnt++;
                j = max(j, rightMost[s[i]-'a']);
                i++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

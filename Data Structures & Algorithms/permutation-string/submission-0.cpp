class Solution {
public:
    bool isMatched(vector<int>& v1, vector<int>& v2)
    {
        for(int i = 0; i < 26; i++)
        {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        vector<int> v1(30, 0), v2(30, 0);

        for(int i = 0; i < s1.size(); i++) v1[s1[i]-'a']++;

        
        for(int l = 0, r = 0; r < s2.size(); r++)
        {
            if(r-l+1 > s1.size())
            {
                v2[s2[l]-'a']--;
                l++;
            }

            v2[s2[r]-'a']++;

            if(isMatched(v1, v2)) return true;
        }
        return false;
    }
};

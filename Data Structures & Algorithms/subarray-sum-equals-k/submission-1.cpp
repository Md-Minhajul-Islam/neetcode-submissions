class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pref = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            pref += nums[i];

            if(mp.count(-k+pref))
            {
                ans += mp[-k+pref];
            }
            mp[pref]++;
        }   
        return ans;
    }
};
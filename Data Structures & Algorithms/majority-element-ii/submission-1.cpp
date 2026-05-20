class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& n: nums) mp[n]++;
        vector<int> res;
        int n = nums.size();
        for(auto [k, v]: mp)
        {
            if(v > (int)(n/3)) res.push_back(k);
        }
        return res;
    }
};
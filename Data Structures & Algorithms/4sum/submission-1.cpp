class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        map<vector<int>, bool> mp;
        int n = nums.size();
        for(int i = 0; i < n-3; i++)
        {
            for(int j = i+1; j < n-2; j++)
            {
                int l = j+1, r = n-1;
                while(l < r)
                {
                    long long sum = 1ll*nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum == target)
                    {
                        vector<int> v = {nums[i], nums[j], nums[l], nums[r]};
                        sort(v.begin(), v.end());
                        mp[v] = 1;
                        l++; r--;
                    }
                    else if(sum > target) r--;
                    else l++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto& v: mp)
        {
            ans.push_back(v.first);
        }
        return ans;
    }
};
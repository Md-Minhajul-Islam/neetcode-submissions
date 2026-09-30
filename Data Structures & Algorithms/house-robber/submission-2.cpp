class Solution {
public:
    // int maxMoney(int curr, vector<int>& nums, vector<int>& memo)
    // {
    //     if(curr >= nums.size()) return 0;
    //     if(memo[curr] != -1) return memo[curr];

    //     return memo[curr] = max(maxMoney(curr+1, nums, memo), nums[curr]+maxMoney(curr+2, nums, memo));
    // }

    int rob(vector<int>& nums) {
        // vector<int> memo(nums.size(), -1);
        // return maxMoney(0, nums, memo);

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};

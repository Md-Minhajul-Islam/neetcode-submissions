class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);

        return max(robHelper(0, nums.size()-1, nums), robHelper(1, nums.size(), nums));
    }

    int robHelper(int start, int end, vector<int>& nums)
    {
        vector<int> dp(end);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        for(int i = start+2; i < end; i++)
        {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp.back();
    }
};
class Solution {
public:
    int maxMoney(int curr, vector<int>& nums, vector<int>& memo)
    {
        if(curr >= nums.size()) return 0;
        if(memo[curr] != -1) return memo[curr];

        return memo[curr] = max(maxMoney(curr+1, nums, memo), nums[curr]+maxMoney(curr+2, nums, memo));
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return maxMoney(0, nums, memo);
    }
};

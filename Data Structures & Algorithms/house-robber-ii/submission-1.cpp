class Solution {
public:
    int maxMoney(int curr, int end, vector<int>& nums, vector<int>& memo)
    {
        if(curr >= end) return 0;
        if(memo[curr] != -1) return memo[curr];

        return memo[curr] = max(maxMoney(curr+1, end, nums, memo), nums[curr]+maxMoney(curr+2, end, nums, memo));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        vector<int> memo(nums.size(), -1);
        int op1 = maxMoney(0, nums.size()-1, nums, memo);
        memo.assign(nums.size(), -1);
        int op2 = maxMoney(1, nums.size(), nums, memo);
        return max(op1, op2);
    }
};
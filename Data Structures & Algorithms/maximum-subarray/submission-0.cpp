class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = nums[0];
        int mnPref = 0;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum-mnPref);
            mnPref = min(mnPref, sum);
        }
        return maxSum;
    }
};

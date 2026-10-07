class Solution {
public:
    vector<int> memo;

    int lengthOfLISHelper(int start, vector<int>& nums)
    {
        // if(start == nums.size()) return 0;
        if(memo[start] != -1) return memo[start];

        int mxLength = 0;
        for(int i = start+1; i < nums.size(); i++)
        {
            if(nums[i] > nums[start])
            {
                mxLength = max(mxLength, 1+lengthOfLISHelper(i, nums));
            }
        }
        return memo[start] = mxLength;
    }
    int lengthOfLIS(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        int mxLength = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            mxLength = max(mxLength, 1+lengthOfLISHelper(i, nums));
        }
        return mxLength;
    }
};

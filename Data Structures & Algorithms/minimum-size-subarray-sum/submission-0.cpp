class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int len = INT_MAX;
        int l = 0, r = 0, curr = 0;
        while(r < nums.size())
        {
            curr += nums[r];
            while(l <= r && curr >= target)
            {
                len = min(len, r-l+1);
                curr -= nums[l++];
            }
            r++;
        }
        if(len == INT_MAX) len = 0;
        return len;
    }
};
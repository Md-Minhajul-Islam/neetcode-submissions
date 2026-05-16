class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        for(int i = 0, j = 0; i < nums.size() && i <= j; i++)
        {
            j = max(j, i+nums[i]);
            if(i == nums.size()-1) return true;
        }
        return false;
    }
};

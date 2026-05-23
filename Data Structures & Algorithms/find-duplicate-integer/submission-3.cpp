class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) nums[i]--;

        int res = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == -1) continue;
            if(nums[i] == i)
            {
                nums[i] = -1;
                continue;
            }
            int n = nums[i];
            if(nums[n] == -1)
            {
                res = n+1;
                break;
            }
            while(nums[n] != -1)
            {
                int temp = nums[n];
                if(temp == n) return n+1;
                nums[n] = -1;
                n = temp;
            }
        }
        return res;
    }
};

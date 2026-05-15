class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int mnInd = 0;
        int l = 0, r = n-1;

        while(l <= r)
        {
            int m = l+(r-l)/2;

            if(nums[m] < nums[mnInd]) mnInd = m;
            
            if(nums[m] >= nums[l] && nums[m] >= nums[r]) l = m+1;
            else r = m-1;
        }

        l = mnInd, r = n-1;
        while(l <= r)
        {
            int m = l+(r-l)/2;

            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m+1;
            else r = m-1;
        }

        l = 0, r = mnInd-1;
        while(l <= r)
        {
            int m = l+(r-l)/2;

            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m+1;
            else r = m-1;
        }
        return -1;

    }
};

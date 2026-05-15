class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int n = nums.size();

        if(nums[0] <= nums[n-1]) return nums[0];

        int left = 0, right = n-1;
        int ans = nums[0];

        while(left < right)
        {
            int mid = left+(right-left)/2;

            if(nums[mid] >= nums[left] && nums[mid] >= nums[right])
            {
                left = mid+1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                right = mid-1;
            }
        }
        if(left == right) ans = min(ans, nums[left]);
        return ans;
    }
};

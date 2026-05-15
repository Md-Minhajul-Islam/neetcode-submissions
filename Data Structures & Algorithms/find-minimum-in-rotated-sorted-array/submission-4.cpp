class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int n = nums.size();

        if(nums[0] <= nums[n-1]) return nums[0];

        int left = 0, right = n-1;
        int ans = nums[0];

        while(left <= right)
        {
            int mid = left+(right-left)/2;

            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[left] && nums[mid] >= nums[right]) left = mid+1;
            else right = mid-1;
        }
        return ans;
    }
};

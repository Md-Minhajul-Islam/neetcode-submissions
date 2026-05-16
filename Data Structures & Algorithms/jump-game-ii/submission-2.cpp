class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size() <= 1) return 0;

        for(int i = 0, j = 0, cnt = 0; i < nums.size() && i <= j; )
        {
            int mx = j;
            while(i <= j)
            {
                mx = max(mx, i+nums[i]);
                i++;
            }
            if(mx > j) cnt++, j = mx;
            if(j >= nums.size()-1) return cnt;
        }
    }
};

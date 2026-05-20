class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k %= n;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            int ind = (i+k)%n;
            while(vis[ind] == false)
            {
                swap(num, nums[ind]);
                vis[ind] = true;
                ind = (ind+k)%n;
            }
        }
    }
};
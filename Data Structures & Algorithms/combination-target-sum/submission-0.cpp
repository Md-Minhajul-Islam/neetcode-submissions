class Solution {
public:
    void combinationHelper(int curr, vector<int>& nums, int target, vector<int>& comb, vector<vector<int>>& combinations)
    {
        if(target == 0)
        {
            if(!comb.empty()) combinations.push_back(comb);
            return;
        }
        if(target < 0 || curr == nums.size()) return;

        comb.push_back(nums[curr]);
        combinationHelper(curr, nums, target-nums[curr], comb, combinations);
        comb.pop_back();

        combinationHelper(curr+1, nums, target, comb, combinations);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combinations;
        vector<int> comb;
        combinationHelper(0, nums, target, comb, combinations);
        return combinations;
    }
};

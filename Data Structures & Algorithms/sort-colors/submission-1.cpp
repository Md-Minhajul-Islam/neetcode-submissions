class Solution {
public:

    void sortColors(vector<int>& nums) {
        vector<int> cnt(5);
        for(auto& n: nums) cnt[n]++;
        nums.clear();
        for(int i = 0; i < 3; i++)
        {
            while(cnt[i]--) nums.push_back(i);
        }
    }
};
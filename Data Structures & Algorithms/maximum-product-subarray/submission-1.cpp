class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1, suff = 1;
        int maxProduct = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            pref *= nums[i];
            suff *= nums[nums.size()-1-i];
            maxProduct = max({maxProduct, pref, suff});
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
        }
        return maxProduct;
    }
};

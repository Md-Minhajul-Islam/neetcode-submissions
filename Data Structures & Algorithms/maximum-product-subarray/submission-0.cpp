class Solution {
public:
    int maxProduct(vector<int>& nums) {
        bool isZero = false;
        vector<vector<int>> lists;
        vector<int> list;
        for(auto &n: nums)
        {
            if(n == 0)
            {
                isZero = true;
                if(!list.empty())
                {
                    lists.push_back(list);
                    list.clear();
                }
            }
            else list.push_back(n);
        }
        if(!list.empty()) lists.push_back(list);

        int maxProduct = isZero ? 0 : INT_MIN;

        for(auto& list: lists)
        {
            int cnt_neg = 0, prod = 1;
            for(auto &l: list)
            {
                if(l < 0) cnt_neg++;
                prod *= l;
            }
            if(cnt_neg%2 && list.size() > 1)
            {
                int pref_prod = 1;
                for(auto &l: list)
                {
                    pref_prod *= l;
                    if(l < 0) break;
                }
                int suff_prod = 1;
                for(int i = list.size()-1; i >= 0; i--)
                {
                    suff_prod *= list[i];
                    if(list[i] < 0) break;
                }
                prod = max(prod/suff_prod, prod/pref_prod);
            }
            maxProduct = max(maxProduct, prod);
        }
        return maxProduct;
    }
};

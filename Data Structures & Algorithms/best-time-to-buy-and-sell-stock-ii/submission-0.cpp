class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int stock = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < stock)
            {
                stock = prices[i];
            }else {
                prof += prices[i]-stock;
                stock = prices[i];
            }
        }
        return prof;
    }
};
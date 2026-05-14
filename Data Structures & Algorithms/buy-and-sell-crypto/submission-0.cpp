
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mn = 1e5, mxProf = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(mn <= prices[i])
            {
                mxProf = max(mxProf, prices[i]-mn);
            }

            mn = min(mn, prices[i]);
        }
        return mxProf;
    }
};

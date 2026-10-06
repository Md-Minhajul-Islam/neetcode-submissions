class Solution {
public:
    vector<int> memo;

    int coinChangeHelper(vector<int>& coins, int amount)
    {
        cout << amount << "\n";
        if(amount == 0) return 0;
        if(amount < 0) return -1;

        if(memo[amount] != -2) return memo[amount];

        int mn = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int op = coinChangeHelper(coins, amount-coins[i]);
            if(op != -1) mn = min(mn, op+1);
        }

        if(mn != INT_MAX) return memo[amount] = mn;
        else return memo[amount] = -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+5, -2);
        return coinChangeHelper(coins, amount);
    }
};

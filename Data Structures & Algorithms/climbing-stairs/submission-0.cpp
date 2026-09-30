class Solution {
public:
    int distinctWays(int n, vector<int>& memo)
    {
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(memo[n] != -1) return memo[n];
        return memo[n] = distinctWays(n-1, memo)+distinctWays(n-2, memo);
    }

    int climbStairs(int n) {
        vector<int> memo(n+2, -1);
        return distinctWays(n, memo);
    }
};

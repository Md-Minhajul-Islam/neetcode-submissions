class Solution {
public:
    vector<vector<int>> memo;
    int uniquePathsFinder(int i, int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(memo[i][j] != -1) return memo[i][j];

        return memo[i][j] = uniquePathsFinder(i+1, j, m, n) + uniquePathsFinder(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        memo.assign(m, vector<int>(n, -1));
        return uniquePathsFinder(0, 0, m, n);
    }
};

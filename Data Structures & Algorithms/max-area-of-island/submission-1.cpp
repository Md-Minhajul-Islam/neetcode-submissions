class Solution {
public:
    int dfs(vector<vector<int>>& grid, int n, int m, int i, int j)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || !grid[i][j]) return 0;

        grid[i][j] = 0;
        int res = 1 
            + dfs(grid, n, m, i-1, j)
            + dfs(grid, n, m, i+1, j)
            + dfs(grid, n, m, i, j-1)
            + dfs(grid, n, m, i, j+1);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!grid[i][j]) continue;
                maxArea = max(dfs(grid, n, m, i, j), maxArea);
            }
        }
        return maxArea;
    }
};

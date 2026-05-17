class Solution {
public:
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j, int& cnt)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || !grid[i][j]) return;

        grid[i][j] = 0;
        cnt++;
        dfs(grid, n, m, i-1, j, cnt);
        dfs(grid, n, m, i+1, j, cnt);
        dfs(grid, n, m, i, j-1, cnt);
        dfs(grid, n, m, i, j+1, cnt);
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
                int cnt = 0;
                dfs(grid, n, m, i, j, cnt);
                maxArea = max(cnt, maxArea);
            }
        }
        return maxArea;
    }
};

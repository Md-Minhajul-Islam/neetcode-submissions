class Solution {
public:

    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;

        grid[i][j] = '0';
        dfs(grid, n, m, i-1, j);
        dfs(grid, n, m, i+1, j);
        dfs(grid, n, m, i, j-1);
        dfs(grid, n, m, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        //vector<vector<bool>> visited(n, vectro<bool>(m));

        int island = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '0') continue;
                island++;
                dfs(grid, n, m, i, j);
            }
        }
        return island;
    }
};

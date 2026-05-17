class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visitedTreasure, int i, int j, int dis)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()
            || grid[i][j] == -1 || visitedTreasure[i][j]) return;
        
        if(grid[i][j] != 0 && grid[i][j] <= dis) return;
        if(grid[i][j] == 0) visitedTreasure[i][j] = true;

        grid[i][j] = min(grid[i][j], dis+1);
        dfs(grid, visitedTreasure, i-1, j, grid[i][j]);
        dfs(grid, visitedTreasure, i+1, j, grid[i][j]);
        dfs(grid, visitedTreasure, i, j-1, grid[i][j]);
        dfs(grid, visitedTreasure, i, j+1, grid[i][j]);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {

        vector<vector<bool>> visitedTreasure(grid.size(), vector<bool>(grid[0].size()));

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 0)
                {
                    dfs(grid, visitedTreasure, i, j, grid[i][j]);
                }
            }
        }
    }
};

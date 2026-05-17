class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for(auto d: dirs)
            {
                int r = i+d[0], c = j+d[1];
                if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != INT_MAX) continue;
                grid[r][c] = grid[i][j]+1;
                q.push({r, c});
            }
        }
    }
};

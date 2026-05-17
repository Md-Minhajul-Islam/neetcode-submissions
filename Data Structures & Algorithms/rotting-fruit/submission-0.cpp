class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2) q.push({i, j, 0});
            }
        }
        int maxTime = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty())
        {
            int i = q.front()[0], j = q.front()[1], t = q.front()[2];
            q.pop();
            for(auto d: dirs)
            {
                int r = i+d[0], c = j+d[1];
                if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 1) continue;
                grid[r][c] = 2;
                q.push({r, c, t+1});
                maxTime = max(maxTime, t+1);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1) return -1; 
            }
        }

        return maxTime;
    }
};

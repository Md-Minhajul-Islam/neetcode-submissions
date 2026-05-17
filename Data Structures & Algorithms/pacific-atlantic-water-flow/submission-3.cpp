class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m)), atl(n, vector<bool>(m));

        for(int c = 0; c < m; c++)
        {
            dfs(heights, pac, 0, c, heights[0][c]);
            dfs(heights, atl, n-1, c, heights[n-1][c]);
        }
        for(int r = 0; r < n; r++)
        {
            dfs(heights, pac, r, 0, heights[r][0]);
            dfs(heights, atl, r, m-1, heights[r][m-1]);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& mark, int i, int j, int prev)
    {
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() 
            || mark[i][j] || heights[i][j] < prev) return;
        mark[i][j] = true;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto& d: dirs)
        {
            int r = i+d[0], c = j+d[1];
            dfs(heights, mark, r, c, heights[i][j]);
        }
    }
    
};

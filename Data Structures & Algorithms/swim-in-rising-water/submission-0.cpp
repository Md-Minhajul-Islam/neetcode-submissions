class Solution {
public:

    int dijkastra(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>>  t(n, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        t[0][0] = grid[0][0];
        minHeap.push({t[0][0], 0, 0});

        while(!minHeap.empty())
        {
            auto vec = minHeap.top();
            minHeap.pop();
            int time = vec[0], i = vec[1], j = vec[2];

            for(auto& dir: dirs)
            {
                int r = i+dir[0], c = j+dir[1];
                if(r < 0 || r >= n || c < 0 || c >= n) continue;
                
                if(t[r][c] > max(grid[r][c], t[i][j]))
                {
                    t[r][c] = max(grid[r][c], t[i][j]);
                    minHeap.push({t[r][c], r, c});
                }
            }
        }
        return t[n-1][n-1];
    }


    int swimInWater(vector<vector<int>>& grid) {
        return dijkastra(grid);
    }
};

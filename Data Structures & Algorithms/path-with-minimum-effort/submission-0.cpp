class Solution {
public:

    int dijkastra(vector<vector<int>>& heights)
    {
        vector<vector<int>> dif(105, vector<int>(105, INT_MAX));
        vector<vector<int>> vis(105, vector<int>(105, INT_MAX));
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int n = heights.size();
        int m = heights[0].size();

        dif[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty())
        {
            auto [d, loc] = pq.top();
            pq.pop();
            vis[loc[0]][loc[1]] = 1;
            for(auto dir: dirs)
            {
                int r = loc[0]+dir[0];
                int c = loc[1]+dir[1];
                if(r >= 0 && r < n && c >= 0 && c < m 
                    && dif[r][c] > max(dif[loc[0]][loc[1]], abs(heights[loc[0]][loc[1]]-heights[r][c])))
                {
                    int diff = max(dif[loc[0]][loc[1]], abs(heights[loc[0]][loc[1]]-heights[r][c]));
                    dif[r][c] = diff;
                    pq.push({diff, {r, c}});
                }
            }
        }

        return dif[n-1][m-1];
        
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkastra(heights);
    }
};
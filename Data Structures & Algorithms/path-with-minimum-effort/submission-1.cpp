class Solution {
public:

    int dijkastra(vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dif (n, vector<int>(m, INT_MAX));
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        priority_queue<vector<int>> minHeap;

        dif[0][0] = 0;
        minHeap.push({0, 0, 0});
        while(!minHeap.empty())
        {
            auto curr = minHeap.top();
            minHeap.pop();
            int diff = curr[0], i = curr[1], j = curr[2];
            for(auto &d: dirs)
            {
                int r = i+d[0], c = j+d[1];

                if(r < 0 || r >= n || c < 0 || c >= m) continue;
                int newDif = max(diff, abs(heights[i][j]-heights[r][c]));
                if(dif[r][c] > newDif)
                {
                    dif[r][c]= newDif;
                    minHeap.push({newDif, r, c});
                }
            }
        }
        return dif[n-1][m-1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkastra(heights);
    }
};
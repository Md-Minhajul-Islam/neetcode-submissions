class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiral;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int r = 0, c = 0;
        while(visited[r][c] == false)
        {
            while(c < n && visited[r][c] == false)
            {
                spiral.push_back(matrix[r][c]);
                visited[r][c] = true;
                c++;
            }
            r++; c--;

            while(r < m && visited[r][c] == false)
            {
                spiral.push_back(matrix[r][c]);
                visited[r][c] = true;
                r++;
            }
            r--; c--;

            while(c >= 0 && visited[r][c] == false)
            {
                spiral.push_back(matrix[r][c]);
                visited[r][c] = true;
                c--;
            }
            r--; c++;

            while(r >= 0 && visited[r][c] == false)
            {
                spiral.push_back(matrix[r][c]);
                visited[r][c] = true;
                r--;
            }
            r++; c++;
        }
        return spiral;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> marked(n, vector<bool>(m));
        for(int c = 0; c < m; c++)
        {
            dfs(board, marked, 0, c);
            dfs(board, marked, n-1, c);
        }
        for(int r = 0; r < n; r++)
        {
            dfs(board, marked, r, 0);
            dfs(board, marked, r, m-1);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(marked[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& marked, int i, int j)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || marked[i][j] || board[i][j] == 'X') return;
        
        marked[i][j] = true;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto& d: dirs)
        {
            dfs(board, marked, i+d[0], j+d[1]);
        }
    }
};

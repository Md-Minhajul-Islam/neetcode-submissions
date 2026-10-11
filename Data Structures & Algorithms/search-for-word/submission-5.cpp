class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0},  {-1, 0}, {0, 1}, {0, -1}};

    bool helper(int i, int r, int c, int m, int n, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited)
    {
        if(i == word.size()) return true;

        bool flag = false;
        for(auto &[x, y]: dir)
        {
            int row = r+x, col = c+y;
            if(row < m && col < n && row >= 0 && col >= 0 && visited[row][col] == false && board[row][col] == word[i])
            {
                visited[row][col] = true;
                if(helper(i+1, row, col, m, n, board, word, visited)) flag = true;
                visited[row][col] = false;
            }
        }
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != word[0]) continue;
                visited[i][j] = true;
                if(helper(1, i, j, m, n, board, word, visited)) return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
};

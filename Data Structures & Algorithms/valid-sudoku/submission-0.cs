public class Solution {

    public bool checkBox(int r, int c, char[][] board)
    {
        bool[] mark = new bool[10];
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i+r][j+c] == '.') continue;
                if(mark[board[i+r][j+c]-'0']) return false;
                mark[board[i+r][j+c]-'0'] = true;
            }
        }
        return true;
    }

    public bool IsValidSudoku(char[][] board) {
        
        for(int i = 0; i < 9; i++)
        {
            bool[] mark = new bool[10];
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue; 
                if(mark[board[i][j]-'0']) return false;
                mark[board[i][j]-'0'] = true;
            }
            Array.Fill(mark, false);
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] == '.') continue;
                if(mark[board[j][i]-'0']) return false;
                mark[board[j][i]-'0'] = true;
            }
        }
        if(checkBox(0, 0, board) && checkBox(0, 3, board) && checkBox(0, 6, board)
            && checkBox(3, 0, board) && checkBox(3, 3, board) && checkBox(3, 6, board)
            && checkBox(6, 0, board) && checkBox(6, 3, board) && checkBox(6, 6, board)) return true;
        else return false;


    }
}

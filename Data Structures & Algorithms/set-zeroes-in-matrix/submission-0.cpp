class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row_zero = false;
        bool first_col_zero = false;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int c = 0; c < n; c++)
        {
            if(matrix[0][c] == 0) first_row_zero = true;
        }
        for(int r = 0; r < m; r++)
        {
            if(matrix[r][0] == 0) first_col_zero = true;
        }

        for(int r = 1; r < m; r++)
        {
            for(int c = 1; c < n; c++)
            {
                if(matrix[r][c] == 0) matrix[r][0] = 0, matrix[0][c] = 0;
            }
        }

        for(int r = 1; r < m; r++)
        {
            for(int c = 1; c < n; c++)
            {
                if(matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
        }

        if(first_row_zero)
        {
            for(int c = 0; c < n; c++) matrix[0][c] = 0;
        }
        if(first_col_zero)
        {
            for(int r = 0; r < m; r++) matrix[r][0] = 0;
        }
    }
};

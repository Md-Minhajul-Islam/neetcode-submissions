class NumMatrix {
public:
    vector<vector<int>> prefMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefMat.assign(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                prefMat[i][j] = matrix[i][j];
                if(i-1 >= 0) prefMat[i][j] += prefMat[i-1][j];
                if(j-1 >= 0) prefMat[i][j] += prefMat[i][j-1];
                if(i-1 >= 0 && j-1 >= 0) prefMat[i][j] -= prefMat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefMat[row2][col2];
        if(row1-1 >= 0) sum -= prefMat[row1-1][col2];
        if(col1-1 >= 0) sum -= prefMat[row2][col1-1];
        if(row1-1 >= 0 && col1-1 >= 0) sum += prefMat[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
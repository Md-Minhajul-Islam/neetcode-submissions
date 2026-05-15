class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;

        int low = 0, high = row;
        while(low <= high)
        {
            int mid = low+(high-low)/2;

            if(target > matrix[mid][col]) low = mid+1;
            else if(target < matrix[mid][0]) high = mid-1;
            else break;
        }

        if(low > high) return false;

        row = low+(high-low)/2;

        int left = 0, right = col;
        
        while(left <= right)
        {
            int mid = left+(right-left)/2;

            if(target > matrix[row][mid]) left = mid+1;
            else if(target < matrix[row][mid]) right = mid-1;
            else return true;
        }
        return false;
    }
};

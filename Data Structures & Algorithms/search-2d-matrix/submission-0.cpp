class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(auto &r: matrix)
        {
            auto it = lower_bound(r.begin(), r.end(), target);

            if(it != r.end() && *it == target) return true;
        }
        return false;
    }
};

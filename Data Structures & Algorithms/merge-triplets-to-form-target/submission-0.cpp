class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> flag(3);

        for(auto& v: triplets)
        {
            int a = v[0], b = v[1], c = v[2];
            
            if(a > target[0] || b > target[1] || c > target[2]) continue;
            if(a == target[0]) flag[0] = true;
            if(b == target[1]) flag[1] = true;
            if(c == target[2]) flag[2] = true;
        }
        return flag[0] && flag[1] && flag[2];
    }
};

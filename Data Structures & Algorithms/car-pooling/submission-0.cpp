class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> range(1009);

        for(auto& trip: trips)
        {
            int pas = trip[0], from = trip[1], to = trip[2];
            range[from] += pas;
            range[to] -= pas;
        }

        for(int i = 1; i < 1009; i++)
        {
            range[i] += range[i-1];
        }

        for(int i = 0; i < 1009; i++)
        {
            if(range[i] > capacity) return false;
        }
        return true;

    }
};
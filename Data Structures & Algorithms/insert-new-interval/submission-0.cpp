class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for(auto i: intervals)
        {
            int l = i[0], r = i[1];
            if(newInterval[0] == -1 && newInterval[1] == -1)
            {
                ans.push_back(i);
            }
            else if(r < newInterval[0])
            {
                ans.push_back(i);
            }
            else if(newInterval[1] < l)
            {
                ans.push_back(newInterval);
                ans.push_back(i);
                newInterval = {-1, -1};
            }
            else
            {
                newInterval[0] = min(newInterval[0], l);
                newInterval[1] = max(newInterval[1], r);
            }
        }
        if(newInterval[0] != -1 && newInterval[1] != -1) ans.push_back(newInterval);
        return ans;
    }
};

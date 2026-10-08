class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& v1, auto& v2){
            return v1[1] < v2[1];
        });

        int removals = 0, prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < prevEnd) removals++;
            else prevEnd = intervals[i][1];
        }
        return removals;
    }
};

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        vector<int> v(1000005);

        for(auto& i: intervals)
        {
            v[i.start] += 1;
            v[i.end] -= 1; 
        }

        int maxRoom = v[0];
        for(int i = 1; i <= 1000000; i++)
        {
            v[i] += v[i-1];
            maxRoom = max(maxRoom, v[i]);
        }
        return maxRoom;
    }
};

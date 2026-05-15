class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long low = 1, high = 1e15, k;

        while(low <= high)
        {
            long long mid = low+(high-low)/2ll;

            long long hours = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                hours += (piles[i]+mid-1)/mid;
            }

            if(hours <= h)
            {
                k = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return k;

    }
};

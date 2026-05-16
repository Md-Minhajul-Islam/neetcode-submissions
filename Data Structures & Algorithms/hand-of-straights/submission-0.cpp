class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        vector<int> cnt(1005);
        for(auto &h: hand) cnt[h]++;

        for(int i = 0; i < 1005; i++)
        {
            if(cnt[i] == 0) continue;
            int j = i+groupSize-1;
            if(j >= 1005) return false;
            int rem = cnt[i];
            for(int k = i; k <= j; k++)
            {
                if(cnt[k] < rem) return false;
                cnt[k] -= rem;
            }
        }
        return true;
    }
};

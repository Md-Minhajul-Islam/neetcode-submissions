class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        multiset<int> ms;
        for(int i = 0; i < people.size(); i++) ms.insert(people[i]);
        int cnt = 0;
        while(ms.size() > 1)
        {
            cnt++;
            auto it = --ms.end();
            auto it2 = ms.upper_bound(limit-*it);
            ms.erase(it);
            if(it2 != ms.begin())
            {
                it2--;
                ms.erase(it2);
            }
        }
        if(!ms.empty()) cnt++;
        return cnt;        
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int sz = position.size();
        vector<pair<int, int>> car;
        for(int i = 0; i < sz; i++) car.push_back({position[i], speed[i]});
        
        sort(car.begin(), car.end(), [&](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        });

        int d1 = target-car[sz-1].first;
        int s1 = car[sz-1].second;

        int fleet = sz;
        for(int i = sz-2; i >= 0; i--)
        {
            int d2 = target-car[i].first;
            int s2 = car[i].second;

            if(d1*s2 >= d2*s1) fleet--;
            else d1 = d2, s1 = s2;
        }
        return fleet;
    }
};

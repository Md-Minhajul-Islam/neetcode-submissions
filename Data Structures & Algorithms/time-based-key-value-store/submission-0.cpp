class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        string ans = "";
        if(!mp.count(key)) return ans;

        int l  = 0, r = mp[key].size()-1;
        while(l <= r)
        {
            int m = l+(r-l)/2;

            if(mp[key][m].first > timestamp) r = m-1;
            else
            {
                ans = mp[key][m].second;
                l = m+1;
            }
        }
        return ans;
    }
};
